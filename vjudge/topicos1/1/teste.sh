#!/usr/bin/env bash
# filepath: /home/kauanfank/Codes/Competitive-Programming/vjudge/topicos1/1/teste.sh

# Compile your code (update filenames as needed)
g++ f.cpp -o f.out

# Make sure we compiled successfully
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Variable to count the number of successful comparisons
pass_count=0

# Execute and compare outputs
for input_file in F/input/*; do
    base_name=$(basename "$input_file")
    output_file="F/output/$base_name"
    
    ./f.out < "$input_file" > temp_output
    
    if diff -b temp_output "$output_file"; then
        # Increment pass_count using arithmetic expansion
        pass_count=$((pass_count + 1))
    else
        echo "Fail in file: $base_name"
    fi
done

# Cleanup
rm -f temp_output

echo "Total passes: $pass_count"