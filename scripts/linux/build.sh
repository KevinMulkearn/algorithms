#!/usr/bin/bash

PROJECT_DIR=$(cd "$(dirname $0)/../.." && pwd)
NUM_CPUS=$(nproc)

cmake  -DCMAKE_BUILD_TYPE=Debug -S "${PROJECT_DIR}" -B "${PROJECT_DIR}/build"

cd "${PROJECT_DIR}/build"

make -j"${NUM_CPUS}"
