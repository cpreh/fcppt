#!/bin/sh

set -e -u

update_cmake \
	src/CMakeLists.txt \
	FCPPT_CORE_FILES \
	-n \
	include/fcppt \
	-r \
	include/fcppt/algorithm \
	include/fcppt/assert \
	include/fcppt/assign \
	include/fcppt/backtrace \
	include/fcppt/config \
	include/fcppt/container \
	include/fcppt/detail \
	include/fcppt/endianness \
	include/fcppt/error \
	include/fcppt/impl \
	include/fcppt/io \
	include/fcppt/math \
	include/fcppt/mpl \
	include/fcppt/number_multiplexer \
	include/fcppt/preprocessor \
	include/fcppt/random \
	include/fcppt/signal \
	include/fcppt/spirit_traits \
	include/fcppt/time \
	include/fcppt/type_traits \
	include/fcppt/variant \
	-n \
	src \
	-r \
	src/backtrace \
	src/endianness \
	src/error \
	src/include \
	src/io \
	src/time

update_cmake \
	src/filesystem/CMakeLists.txt \
	FCPPT_FILESYSTEM_FILES \
	include/fcppt/filesystem \
	src/filesystem

update_cmake \
	src/log/CMakeLists.txt \
	FCPPT_LOG_FILES \
	include/fcppt/log \
	src/log

update_cmake \
	doc/CMakeLists.txt \
	FCPPT_DOC_FILES \
	include \
	examples \
	-e ".*" \
	doc
