#!/usr/bin/env bash

# Usage: ./test_set.sh <LETTER>
# Example: ./test_set.sh A
# To call a specific function: source teste.sh && function_name <args>

letter="$1"
package="$2" # Caso necessário

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
  return 0
}

clean() {
	local l="${1:-$letter}"
	# echo "Cheguei aqui $l"
	rm -rf "$l"
}

test_setup() {
	local letter="$1"
	# Convert provided letter to uppercase for folder structure
	uppercase_letter=$(echo "$letter" | tr '[:lower:]' '[:upper:]')
	echo ${uppercase_letter}.zip

	
	cp ~/ContestPackages/${package}/${uppercase_letter}.zip "./"
	unzip "./${uppercase_letter}.zip"

	rm -rf "./compare"
	rm -rf "./compile"
	rm -rf "./description"
	rm -rf "./limits"
	rm -rf "./run"
	rm -rf "./tests"

	mkdir "./${letter}"

	mv "./input" "./${letter}"
	mv "./output" "./${letter}"

	# Create input and output directories if they don't exist
	
	return 0
}

compile_program() {
  local letter="$1"
  # Compile the program
  g++ -std=c++17 "${letter}.cpp" -o "${letter}temp"

  if [ ! -f "${letter}temp" ]; then
    echo "Compilation failed."
    return 1
  fi
  return 0
}

run_tests() {
  local letter="$1"
  local count=0
  local testCount=0

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
    fi
  done

  echo "Passed $count/$testCount tests."
}

# Only execute the main function if the script is being run directly, not sourced
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
  trap cleanup EXIT INT
	if [ ! -d "$letter" ]; then
		test_setup "$letter"
	else
		echo "Directory '$letter' already exists. Skipping setup."
	fi
  compile_program "$letter" || exit 1
  run_tests "$letter"
fi