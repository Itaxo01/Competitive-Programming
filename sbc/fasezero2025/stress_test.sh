#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo "Setting up stress testing..."

# Compile all programs
echo "Compiling programs..."
g++ -o gen_tree gen_tree.cpp
if [ $? -ne 0 ]; then
    echo -e "${RED}Failed to compile gen_tree.cpp${NC}"
    exit 1
fi

g++ -o b1 b.cpp
if [ $? -ne 0 ]; then
    echo -e "${RED}Failed to compile b.cpp${NC}"
    exit 1
fi

g++ -o b2 b_teste.cpp
if [ $? -ne 0 ]; then
    echo -e "${RED}Failed to compile b_teste.cpp${NC}"
    exit 1
fi

echo -e "${GREEN}All programs compiled successfully!${NC}"

# Create directories for test cases
mkdir -p failing_tests
mkdir -p temp_tests

# Counter for different outputs
differences_found=0
total_tests=0

# Time tracking variables
total_time_b1=0
total_time_b2=0

echo "Starting stress testing with up to 100 random test cases..."

for i in {1..100}; do
    # Generate random n between 2 and 1000 (adjust range as needed)
    n=$((2 + RANDOM % 99999))
    
    echo -n "Test $i (n=$n): "
    
    # Generate test case
    ./gen_tree $n > temp_tests/input_$i.txt
    
    if [ $? -ne 0 ]; then
        echo -e "${RED}Failed to generate test case $i${NC}"
        continue
    fi
    
    # Run both programs and measure time
    start_time1=$(date +%s.%N)
    timeout 5s ./b1 < temp_tests/input_$i.txt > temp_tests/output1_$i.txt 2>/dev/null
    exit_code1=$?
    end_time1=$(date +%s.%N)
    
    start_time2=$(date +%s.%N)
    timeout 5s ./b2 < temp_tests/input_$i.txt > temp_tests/output2_$i.txt 2>/dev/null
    exit_code2=$?
    end_time2=$(date +%s.%N)
    
    # Calculate execution times (only if programs completed successfully)
    if [ $exit_code1 -eq 0 ]; then
        time_b1=$(echo "$end_time1 - $start_time1" | bc -l)
        total_time_b1=$(echo "$total_time_b1 + $time_b1" | bc -l)
    fi
    
    if [ $exit_code2 -eq 0 ]; then
        time_b2=$(echo "$end_time2 - $start_time2" | bc -l)
        total_time_b2=$(echo "$total_time_b2 + $time_b2" | bc -l)
    fi
    
    # Check if programs ran successfully
    if [ $exit_code1 -ne 0 ] || [ $exit_code2 -ne 0 ]; then
        if [ $exit_code1 -eq 124 ] || [ $exit_code2 -eq 124 ]; then
            echo -e "${YELLOW}TIMEOUT${NC}"
        else
            echo -e "${YELLOW}RUNTIME ERROR${NC}"
        fi
        # Save the problematic input
        cp temp_tests/input_$i.txt failing_tests/runtime_error_$i.txt
        continue
    fi
    
    # Compare outputs
    if ! diff -q temp_tests/output1_$i.txt temp_tests/output2_$i.txt > /dev/null; then
        echo -e "${RED}DIFFERENT OUTPUTS!${NC}"
        differences_found=$((differences_found + 1))
        
        # Save the failing test case
        cp temp_tests/input_$i.txt failing_tests/different_output_$i.txt
        
        echo "  Input saved to: failing_tests/different_output_$i.txt"
        echo "  b.cpp output: $(cat temp_tests/output1_$i.txt)"
        echo "  b_teste.cpp output: $(cat temp_tests/output2_$i.txt)"
        echo ""
        
        # Stop after finding 5 differences to avoid spam
        if [ $differences_found -ge 5 ]; then
            echo -e "${YELLOW}Found 5 differences, stopping early.${NC}"
            break
        fi
    else
        echo -e "${GREEN}OK${NC}"
    fi
    
    total_tests=$((total_tests + 1))
done

# Clean up temporary files
rm -rf temp_tests

echo ""
echo "=== STRESS TEST RESULTS ==="
echo "Total tests run: $total_tests"
echo "Differences found: $differences_found"

# Display timing results
echo ""
echo "=== TIMING RESULTS ==="

# Set locale to use dot as decimal separator for consistent formatting
export LC_NUMERIC=C

if (( $(echo "$total_time_b1 > 0" | bc -l) )); then
    # Use echo and bc for consistent decimal formatting
    total_formatted=$(echo "scale=6; $total_time_b1" | bc -l)
    avg_formatted=$(echo "scale=6; $total_time_b1 / $total_tests" | bc -l)
    echo "Total time for b.cpp: ${total_formatted} seconds"
    echo "Average time per test for b.cpp: ${avg_formatted} seconds"
else
    echo "No successful runs for b.cpp"
fi

if (( $(echo "$total_time_b2 > 0" | bc -l) )); then
    # Use echo and bc for consistent decimal formatting
    total_formatted=$(echo "scale=6; $total_time_b2" | bc -l)
    avg_formatted=$(echo "scale=6; $total_time_b2 / $total_tests" | bc -l)
    echo "Total time for b_teste.cpp: ${total_formatted} seconds"
    echo "Average time per test for b_teste.cpp: ${avg_formatted} seconds"
else
    echo "No successful runs for b_teste.cpp"
fi

if (( $(echo "$total_time_b1 > 0 && $total_time_b2 > 0" | bc -l) )); then
    if (( $(echo "$total_time_b1 < $total_time_b2" | bc -l) )); then
        speedup=$(echo "scale=2; $total_time_b2 / $total_time_b1" | bc -l)
        echo "b.cpp is ${speedup}x faster than b_teste.cpp"
    else
        speedup=$(echo "scale=2; $total_time_b1 / $total_time_b2" | bc -l)
        echo "b_teste.cpp is ${speedup}x faster than b.cpp"
    fi
fi

if [ $differences_found -eq 0 ]; then
    echo -e "${GREEN}All tests passed! Both programs produce identical outputs.${NC}"
else
    echo -e "${RED}Found $differences_found test cases with different outputs.${NC}"
    echo "Failing test cases saved in failing_tests/ directory:"
    ls -la failing_tests/
fi

echo ""
echo "To run a specific failing test case manually:"
echo "  ./b1 < failing_tests/different_output_X.txt"
echo "  ./b2 < failing_tests/different_output_X.txt"
