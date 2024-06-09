$ARG = $args[0]

$SCRIPT_PATH = $MyInvocation.MyCommand.Path
$SCRIPT_DIR_PATH = Split-Path $SCRIPT_PATH

$BUILD_DIR = "builds"
$BUILD_DIR_PATH = Join-Path -Path $SCRIPT_DIR_PATH -ChildPath $BUILD_DIR
if ($ARG -eq "build") {
    if (-Not (Test-Path -Path $BUILD_DIR_PATH)) {
        mkdir $BUILD_DIR | Out-Null
        Set-Location -Path $BUILD_DIR_PATH;
        cmake ..
    }

    Set-Location -Path $BUILD_DIR_PATH;

    cmake --build .
} elseif ($ARG -eq "cmake") {
    Set-Location -Path $BUILD_DIR_PATH;

    cmake ..
} elseif ($ARG -eq "run") {
    $RUN_DIR = "Debug"
    $RUN_DIR_PATH = Join-Path -Path $BUILD_DIR_PATH -ChildPath $RUN_DIR

    Set-Location -Path $RUN_DIR_PATH;

    .\Example1.exe
} else {
    Write-Host "Run with 'build', 'cmake' or 'run'"
}

Set-Location -Path $SCRIPT_DIR_PATH;
