#!/usr/bin/bash

PROJECT_DIR=$(cd "$(dirname $0)/../.." && pwd)

"${PROJECT_DIR}/scripts/linux/build.sh"

ctest --output-on-failure