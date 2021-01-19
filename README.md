# Linux (Ubuntu) Build Instructions: #

## Requirements ##

* CMake
* GCC
* GTest
* Make

## Install Tools ##

    sudo apt-get install build-essential
    sudo apt-get install libgtest-dev
    sudo apt-get install cmake

### Configure GTest ###

Build GTest

    cd /usr/src/gtest
    sudo cmake CMakeLists.txt
    sudo make

Copy GTest libraries to general directory

    sudo cp lib/*.a /usr/lib

Make symbolic link to local lib

    sudo mkdir /usr/local/lib/googletest
    sudo ln -s /usr/lib/libgtest.a /usr/local/lib/googletest/libgtest.a
    sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/googletest/libgtest_main.a

## Build Repo ##

    mkdir build
    cd build
    ../scripts/linux/build.sh

## Run Unit Tests ##

    cd build
    ../scripts/linux/test.sh

# Windows (10) Build Instructions: #

TODO

## Requirements ##

* CMake
* GTest
* Make
* MinGW

## Download GTest ##

    git clone https://github.com/google/googletest.git

(or hit the download button)

## Build GTest ##

    cd googletest
    mkdir build
    cd build
    cmake -G "MinGW Makefiles" ..
    make

## Configure GTest ##

Copy the \googletest\googletest\include\gtest folder to \MinGW\include

Copy the generated library files from \googletest\build\lib to \MinGW\lib

## Build Repo ##

    cd scripts/windows
    build.bat

## Run Unit Tests ##

    cd scripts/windows
    test.bat

TODO: Fix - Unit test will not work unless .dll are copied into unit test folder with exectable. 
