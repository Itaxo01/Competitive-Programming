#!/bin/bash

# Check if any arguments were provided
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <letter1> <letter2> ..."
    exit 1
fi

# Loop through all arguments passed to the script
for letter in "$@"; do
    echo "Cleaning up for '${letter}'..."

    # Remove the directory named after the argument
    rm -rf "${letter}"

    # Convert the argument to uppercase
    uppercase_letter=$(echo "$letter" | tr '[:lower:]' '[:upper:]')

    # Remove the corresponding zip file
    # The -f flag prevents errors if the file doesn't exist
    rm -f "${uppercase_letter}.zip"
done

echo "Cleanup complete."