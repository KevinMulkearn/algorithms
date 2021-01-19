ECHO OFF

set PROJECT_DIR=%CD%

CALL build.bat

cd ../../build

ctest --output-on-failure

cd %PROJECT_DIR%

PAUSE