#!/usr/bin/env bash

ARGS=(--library fcppt)

find libs examples test \( \( -name '*.hpp' -o -name '*.cpp' \) \) -exec update_headers '{}' "${ARGS[@]}" \;
