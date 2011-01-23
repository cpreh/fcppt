#!/bin/sh
update_cmake \
	CMakeLists.txt \
	FCPPT_FILES \
	include \
	src \
	|| exit

mv CMakeLists.txt.new CMakeLists.txt
