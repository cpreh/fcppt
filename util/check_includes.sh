#!/bin/sh

INCLUDE_BINARY="check_includes"

"${INCLUDE_BINARY}" include || exit -1

"${INCLUDE_BINARY}" libs/filesystem/include || exit -1

"${INCLUDE_BINARY}" libs/log/include || exit -1
