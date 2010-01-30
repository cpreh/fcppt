#!/bin/sh
for folder in examples include src 'test' ; do
	find ${folder} -not -name facet.cpp -not -name ratio.hpp -name '*.?pp' -exec update_license '{}' util/license_template.hpp \;
done
