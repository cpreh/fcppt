#!/bin/sh
pushd include > /dev/null
convenience_headers fcppt || exit -1
# remove config.hpp, because these headers cannot be included in any order
rm fcppt/config/config.hpp || exit -1
popd > /dev/null
multi_update_license util/license_paths.json
