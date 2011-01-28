#!/bin/sh
update_cmake \
	CMakeLists.txt \
	FCPPT_FILES \
	include \
	src \
	|| exit -1

mv CMakeLists.txt.new CMakeLists.txt
