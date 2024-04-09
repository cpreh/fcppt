#!/bin/sh

set -e -u

toupper()
{
	echo $(tr 'a-z' 'A-Z' <<< "$1")
}

update_sublibrary()
{
	local sublibrary="$1"
	local upperpath=$(toupper "${sublibrary}")
	local libdir=libs/"${sublibrary}"

	update_cmake.sh \
		"${libdir}"/files.txt \
		"${libdir}"
}

LIBS=(
	boost
	catch
	core
	filesystem
	log
	options
	parse
)

for lib in ${LIBS[@]} ; do
	update_sublibrary $lib
done

update_cmake.sh \
	doc/all_files.txt \
	libs/boost/include \
	libs/catch/include \
	libs/core/include \
	libs/filesystem/include \
	libs/log/include \
	libs/options/include \
	libs/parse/include \
	examples

FIND_PATTERN=".*" update_cmake.sh doc/doc_files.txt doc
