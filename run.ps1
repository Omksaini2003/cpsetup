# Define paths for the EXE folder and files
$exeFolder = ".\exe"
$currentFile = if ($args.Count -gt 0) { "$($args[0]).cpp" } else { "a.cpp" }
$outputFile = if ($args.Count -gt 0) { "$exeFolder\$($args[0]).exe" } else { "$exeFolder\a.exe" }

$outputTxt = ".\files\output.txt"
$inputTxt = ".\files\input.txt"
$errorTxt = ".\files\ERROR.txt"
$debugTxt = ".\files\debug.txt"


# Ensure EXE folder exists
if (-not (Test-Path $exeFolder)) {
    New-Item -ItemType Directory -Path $exeFolder
}

# Clear old contents of output.txt and ERROR.txt before starting
Clear-Content $errorTxt -ErrorAction SilentlyContinue
Set-Content $outputTxt -Value $null -Encoding UTF8 -ErrorAction SilentlyContinue
Set-Content $debugTxt -Value $null -Encoding UTF8 -ErrorAction SilentlyContinue

# Check if the file exists and is a C++ file
if (Test-Path $currentFile) {
    Write-Host "Compiling $currentFile..."

    # Capture all output and errors from the g++ compilation command
    $compileResult = g++ $currentFile -o $outputFile -O2 -std=c++17 2>&1

    # Check if compilation was successful
    if ($?) {
        Write-Host "Compilation successful. Running $outputFile..."

        # Set up the process to run the compiled executable from EXE folder
        $process = New-Object System.Diagnostics.Process
        $process.StartInfo.FileName = $outputFile
        
        # Redirect input, output, and error streams
        $process.StartInfo.RedirectStandardInput = $true
        $process.StartInfo.RedirectStandardOutput = $true
        $process.StartInfo.RedirectStandardError = $true
        $process.StartInfo.UseShellExecute = $false

        # Start the process
        $process.Start()

        # Write the contents of input.txt to the process' standard input
        $inputFile = $inputTxt
        if (Test-Path $inputFile) {
            $input_ = Get-Content $inputFile
            foreach ($line in $input_) {
                $process.StandardInput.WriteLine($line)
            }
        }

        # Read the output and error from the process and write to output.txt and ERROR.txt
        $process.StandardOutput.ReadToEnd() | Out-File $outputTxt
        $process.StandardError.ReadToEnd() | Out-File $errorTxt

        # Wait for the process to exit
        $process.WaitForExit()

        Write-Host "Execution finished. Check output.txt and ERROR.txt for results."
    } else {
        Write-Host "Compilation failed. Check ERROR.txt for errors."
        # Write the complete compile errors to ERROR.txt
        $compileResult | Out-File $errorTxt -Force
    }
} else {
    Write-Host "No C++ file found: $currentFile"
    # Log the absence of the file to ERROR.txt
    "No C++ file found: $currentFile" | Out-File $errorTxt -Force
}
