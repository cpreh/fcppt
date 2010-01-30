#!/bin/sh
for folder in examples include src 'test' ; do
	find ${folder} -name '*.?pp' -exec update_license '{}' util/license_template.hpp \;
done
