#!/bin/sh

INCLUDE_BINARY="check_includes"

"${INCLUDE_BINARY}" include || exit -1

"${INCLUDE_BINARY}" src/include || exit -1

"${INCLUDE_BINARY}" src/log/include || exit -1
