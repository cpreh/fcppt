#!/bin/sh

INCLUDE_BINARY="check_includes"

find libs -name include -exec "${INCLUDE_BINARY}" '{}' \; || exit
