#!/usr/bin/env bash

LIBS=(--library fcppt)
DIRS=(examples libs test)

prettify_includes "${LIBS[@]}" "${DIRS[@]}"
