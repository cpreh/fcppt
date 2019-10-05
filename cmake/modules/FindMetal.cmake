find_path(
	Metal_INCLUDE_DIR
	metal.hpp
	HINTS
	"${Metal_INCLUDEDIR}"
)

include(
	FindPackageHandleStandardArgs
)

find_package_handle_standard_args(
	Metal
	DEFAULT_MSG
	Metal_INCLUDE_DIR
)

if(
	Metal_FOUND
)
	add_library(
		Metal
		INTERFACE
		IMPORTED
	)

	set_property(
		TARGET
		Metal
		PROPERTY
		INTERFACE_INCLUDE_DIRECTORIES
		"${Metal_INCLUDE_DIR}"
	)
endif()

mark_as_advanced(
	Metal_INCLUDE_DIR
)
