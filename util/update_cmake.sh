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

	update_cmake \
		"${libdir}"/CMakeLists.txt \
		FCPPT_"${upperpath}"_FILES \
		"${@:2}" \
		"${libdir}"
}

update_sublibrary core

update_sublibrary filesystem

update_sublibrary log

update_cmake \
	doc/CMakeLists.txt \
	FCPPT_DOC_FILES \
	libs/core/include \
	libs/filesystem/include \
	libs/log/include \
	examples \
	-e ".*" \
	doc
