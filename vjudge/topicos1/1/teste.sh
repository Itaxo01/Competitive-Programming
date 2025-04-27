#!/usr/bin/env bash

# Usage: ./test_set.sh <LETTER>
# Example: ./test_set.sh A

letter="$1"

trap cleanup EXIT INT
# Cleanup
cleanup() {
  echo "Cleaning done"
  for inputFile in "${letter}/input/"*; do
    testName=$(basename "$inputFile")
    if [ -f "/tmp/${testName}.out" ]; then
      rm "/tmp/${testName}.out"
    fi
  done
  rm -f "${letter}temp"
  trap - EXIT
  exit 1
}


# Compile the program
g++ -std=c++20 -O2 "${letter}.cpp" -o "${letter}temp"

if [ ! -f "${letter}temp" ]; then
  echo "Compilation failed."
  exit 1
fi

count=0
testCount=0

# For each input file in e.g. A/input/A__*
for inputFile in "${letter}/input/"*; do
  # Skip if no matching files
  [ -e "$inputFile" ] || continue

  testCount=$((testCount+1))
  testName=$(basename "$inputFile")
  echo "Running test $testName"
  # Run and store output in temporary file
  start_time=$(date +%s%N)
  "./${letter}temp" < "$inputFile" > "/tmp/${testName}.out"
  end_time=$(date +%s%N)

  tempo_file=$(( (end_time - start_time) / 1000000 ))
  # Compare with expected output
  if diff -q "/tmp/${testName}.out" "${letter}/output/${testName}" >/dev/null; then
    count=$((count+1))
    echo "Passed in $tempo_file ms"
  else
    echo "Mismatch in test: $testName"
    echo "Expected output: "
    cat "${letter}/output/${testName}"
    echo "Actual output: "
    cat "/tmp/${testName}.out"
  fi
done

echo "Passed $count/$testCount tests."


