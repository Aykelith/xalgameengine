$SCRIPT_PATH = $MyInvocation.MyCommand.Path
$SCRIPT_DIR_PATH = Split-Path $SCRIPT_PATH

$DIR_PATH = Join-Path -Path $SCRIPT_DIR_PATH -ChildPath "..\libs\glm" 

Set-Location -Path $DIR_PATH;

cmake -DGLM_BUILD_TESTS=OFF -DBUILD_SHARED_LIBS=OFF -B build .
cmake --build build -- /p:Configuration=Release
cmake --install build --prefix install

Set-Location -Path $SCRIPT_DIR_PATH;
