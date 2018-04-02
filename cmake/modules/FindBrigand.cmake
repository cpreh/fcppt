find_path(
	Brigand_INCLUDE_DIR
	brigand/brigand.hpp
	HINTS
	"${Brigand_INCLUDEDIR}"
)

include(
	FindPackageHandleStandardArgs
)

find_package_handle_standard_args(
	Brigand
	DEFAULT_MSG
	Brigand_INCLUDE_DIR
)

if(
	Brigand_FOUND
)
	add_library(
		Brigand
		INTERFACE
		IMPORTED
	)

	set_property(
		TARGET
		Brigand
		PROPERTY
		INTERFACE_INCLUDE_DIRECTORIES
		"${Brigand_INCLUDE_DIR}"
	)
endif()

mark_as_advanced(
	Brigand_INCLUDE_DIR
)
