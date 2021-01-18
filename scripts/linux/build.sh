#!/usr/bin/bash

PROJECT_DIR=$(cd "$(dirname $0)/../.." && pwd)

cmake  -DCMAKE_BUILD_TYPE=Debug -S "${PROJECT_DIR}" -B "${PROJECT_DIR}/build"

cd "${PROJECT_DIR}/build"

make
