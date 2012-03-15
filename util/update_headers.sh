#!/bin/sh
multi_update_license util/license_paths.json || exit -1
util/prettify_includes.sh
