#!/bin/bash

# Compile the tenis.cpp file
g++ /mnt/d/obi/tenis/tenis.cpp -o /mnt/d/obi/tenis/tenis

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Find all .in files in the tenis folder and its subfolders
find /mnt/d/obi/tenis/ -type f -name "*.in" | while read input_file; do
    # Get the base name of the input file (without extension)
    base_name=$(basename "$input_file" .in)
    
    # Define the expected output file
    expected_output_file="${input_file%.in}.sol"
    
    # Define the actual output file
    actual_output_file="${input_file%.in}.out"
    
    # Run the compiled program with the input file and capture the output
    /mnt/d/obi/tenis/tenis < "$input_file" > "$actual_output_file"
    
    # Compare the program output with the expected output
    if diff -b "$actual_output_file" "$expected_output_file" > /dev/null; then
        echo "Test ${base_name}: PASS"
    else
        echo "Test ${base_name}: FAIL"
    fi
done