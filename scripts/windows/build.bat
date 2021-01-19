ECHO OFF

set PROJECT_DIR=%CD%

cd ../..

cmake -G "MinGW Makefiles" -S . -B build

cd build

make

cd %PROJECT_DIR%

PAUSE