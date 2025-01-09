# Get the currently opened file's full path
$currentFile = (Get-Location).Path + "\" + (gci -Filter "*.cpp" | Select-Object -First 1).Name

# Extract the file name without extension
$outputFile = [System.IO.Path]::GetFileNameWithoutExtension($currentFile) + ".exe"

# Check if the file exists and is a C++ file
if (Test-Path $currentFile) {
    Write-Host "Compiling $currentFile..."
    
    # Compile the C++ file using g++
    g++ $currentFile -o $outputFile

    # Check if compilation was successful
    if ($?) {
        Write-Host "Compilation successful. Running $outputFile..."
        # Run the executable using the resolved output file path
        & ".\$outputFile"
    } else {
        Write-Host "Compilation failed."
    }
} else {
    Write-Host "No C++ file found in the current directory."
}
