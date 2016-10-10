fcppt_utils_link_target(
	fcppt_core
)

fcppt_utils_link_target(
	fcppt_log
)

function(
	make_fcppt_example
	MAINNAME
)
	set(
		OPTION_ARGS
		IS_C
	)

	set(
		SINGLE_ARGS
		SUBNAME
	)

	set(
		MULTI_ARGS
		LINK_LIBS
		COMPILE_DEFINITIONS
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		"${SINGLE_ARGS}"
		"${MULTI_ARGS}"
		${ARGN}
	)

	if(
		"${_SUBNAME}"
		STREQUAL
		""
	)
		set(
			FCPPT_EXAMPLE_NAME_SUFFIX
			${MAINNAME}
		)
	else()
		set(
			FCPPT_EXAMPLE_NAME_SUFFIX
			${_SUBNAME}_${MAINNAME}
		)
	endif()

	set(
		FCPPT_EXAMPLE_NAME
		fcppt_example_${FCPPT_EXAMPLE_NAME_SUFFIX}
	)

	if(
		${_IS_C}
	)
		set(
			SUFFIX
			"c"
		)
	else()
		set(
			SUFFIX
			"cpp"
		)
	endif()

	add_executable(
		${FCPPT_EXAMPLE_NAME}
		${MAINNAME}.${SUFFIX}
	)

	target_compile_definitions(
		${FCPPT_EXAMPLE_NAME}
		PRIVATE
		"${_COMPILE_DEFINITIONS}"
	)

	target_include_directories(
		${FCPPT_EXAMPLE_NAME}
		PRIVATE
		${Boost_INCLUDE_DIRS}
		${FCPPT_UTILS_PROJECT_BINARY_DIR}/include
	)

	if(
		NOT _IS_C
	)
		fcppt_utils_set_target_compiler_flags(
			${FCPPT_EXAMPLE_NAME}
		)
	endif()

	target_link_libraries(
		${FCPPT_EXAMPLE_NAME}
		PRIVATE
		${_LINK_LIBS}
	)

	string(
		REPLACE
		"_"
		"/"
		FOLDER_NAME
		"${_SUBNAME}"
	)

	if(
		NOT
		"${FOLDER_NAME}"
		STREQUAL
		""
	)
		set(
			FOLDER_NAME
			"/${FOLDER_NAME}"
		)
	endif()

	set_target_properties(
		${FCPPT_EXAMPLE_NAME}
		PROPERTIES
		FOLDER
		"fcppt/examples${FOLDER_NAME}"
	)
endfunction()

function(
	add_fcppt_example
)
	make_fcppt_example(
		${ARGN}
	)
endfunction()

add_fcppt_example(
	algorithm
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	assert
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	assert_complete
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	assign
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	backtrace
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	cast
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	codecvt
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	config
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	coding_style
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	coding_style_asthetic
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	cyclic_iterator
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	endianness
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	enum
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	either
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	homogenous_pair
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	literal
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	no_cpp
	IS_C
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	noncopyable
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	optional
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	output_tm
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	record
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	smart_ptr_deleter
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	shared_ptr
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	string
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	string_conversion
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	strong_typedef
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	type_iso
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	type_traits
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	unique_ptr
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	version
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	visibility
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	weak_ptr
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_subdirectory(
	cast
)

add_subdirectory(
	container
)

add_subdirectory(
	io
)

add_subdirectory(
	log
)

add_subdirectory(
	math
)

add_subdirectory(
	mpl
)

add_subdirectory(
	preprocessor
)

add_subdirectory(
	random
)

add_subdirectory(
	signal
)

add_subdirectory(
	variant
)
