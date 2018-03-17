include(
	CMakeParseArguments
)

option(
	FCPPT_CATCH_LINK_STATIC
	"Link to catch statically"
	OFF
)

if(
	FCPPT_CATCH_LINK_STATIC
)
	set(
		FCPPT_CATCH_LIB_TYPE
		"STATIC"
	)

	message(
		WARNING
		"Linking to Catch statically will drastically increase the
		size of each test case"
	)
else()
	set(
		FCPPT_CATCH_LIB_TYPE
		"SHARED"
	)
endif()

add_library(
	catch_main
	${FCPPT_CATCH_LIB_TYPE}
	catch_main.cpp
)

target_link_libraries(
	catch_main
	PRIVATE
	Catch2::Catch
)

function(
	add_fcppt_test
	PATH_NAME
)
	set(
		OPTION_ARGS
		NO_CODE
	)

	set(
		MULTI_ARGS
		LINK_LIBS
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	if(
		_NO_CODE
	)
		set(
			NO_CODE
			NO_CODE
		)
	endif()

	fcppt_utils_add_test(
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/test
		"${PATH_NAME}"
		${NO_CODE}
		LINK_LIBS
			${_LINK_LIBS}
			catch_main
			Catch2::Catch
			fcppt_core_interface
	)
endfunction()

fcppt_utils_link_target(
	fcppt_core
)

if(
	ENABLE_FILESYSTEM
)
	fcppt_utils_link_target(
		fcppt_filesystem
	)
endif()

fcppt_utils_link_target(
	fcppt_log
)

fcppt_utils_link_target(
	fcppt_options
)

if(
	ENABLE_BOOST
)
	set(
		FCPPT_TEST_BOOST_INTERFACE
		fcppt_boost_interface
	)
endif()

add_fcppt_test(
	absurd
	NO_CODE
)

add_subdirectory(
	algorithm
)

add_subdirectory(
	assert
)

add_subdirectory(
	assign
)

add_fcppt_test(
	bit
)

if(
	ENABLE_BOOST
)
	add_fcppt_test(
		boost_units_value
		LINK_LIBS
			fcppt_boost_interface
	)
endif()

add_subdirectory(
	brigand
)

add_subdirectory(
	cast
)

add_fcppt_test(
	codecvt
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	const
)

add_subdirectory(
	container
)

add_fcppt_test(
	cyclic_iterator
)

add_subdirectory(
	either
)

add_fcppt_test(
	endianness
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_subdirectory(
	enum
)

add_fcppt_test(
	extract_from_string
)

if(
	ENABLE_FILESYSTEM
)
	add_subdirectory(
		filesystem
	)
endif()

add_fcppt_test(
	function
)

add_fcppt_test(
	homogenous_pair
)

add_fcppt_test(
	insert_to_string
)

add_fcppt_test(
	int_range
)

add_subdirectory(
	io
)

add_subdirectory(
	iterator
)

add_subdirectory(
	intrusive
)

add_fcppt_test(
	literal
	LINK_LIBS
		${FCPPT_TEST_BOOST_INTERFACE}
)

add_fcppt_test(
	make_unique_ptr
)

add_subdirectory(
	math
)

add_fcppt_test(
	move_clear
)

add_fcppt_test(
	move_if_rvalue
)

add_subdirectory(
	optional
)

add_subdirectory(
	options
)

add_subdirectory(
	random
)

add_subdirectory(
	range
)

add_subdirectory(
	record
)

add_fcppt_test(
	reference
)

add_fcppt_test(
	reference_to_base
)

add_fcppt_test(
	reference_to_const
)

if(
	ENABLE_BOOST
)
	add_fcppt_test(
		scoped_state_machine
		LINK_LIBS
			fcppt_boost_interface
	)
endif()

add_subdirectory(
	shared_ptr
)

add_subdirectory(
	signal
)

add_subdirectory(
	strong_typedef
)

add_subdirectory(
	type_traits
)

add_fcppt_test(
	unique_ptr_dynamic_cast
)

add_fcppt_test(
	unique_ptr_from_std
)

add_fcppt_test(
	unit
)

add_subdirectory(
	variant
)
