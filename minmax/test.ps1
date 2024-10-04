# Variables
$source = "minmax.cpp"
$executable = "a.exe"
$testCasesDir = "minmax"
$passCount = 0
$failCount = 0

# Compile the C++ code
g++ $source -o a.exe
if ($LASTEXITCODE -ne 0) {
    Write-Host "Compilation failed!"
    exit 1
}

# Loop through each test case directory
foreach ($testDir in Get-ChildItem $testCasesDir -Directory) {
    Write-Host "Running tests in $($testDir.Name)..."
    
    for ($i = 1; $i -le 2; $i++) {
        $inputFile = "$($testDir.FullName)\$i.in"
        $expectedOutputFile = "$($testDir.FullName)\$i.sol"
        $actualOutputFile = "$($testDir.FullName)\$i.out"

        # Run the program with the input file and save the output
        Get-Content  $inputFile | .\a.exe >$actualOutputFile

        # Compare the actual output with the expected output
        if ((Get-Content $expectedOutputFile) -eq (Get-Content $actualOutputFile)) {
            Write-Host "Test $i PASSED"
            $passCount++
        } else {
            Write-Host "Test $i FAILED"
            $failCount++
        }
    }
    
    Write-Host ""
}

# Summary
Write-Host "-----------------"
Write-Host "Total Passed: $passCount"
Write-Host "Total Failed: $failCount"

# Cleanup
