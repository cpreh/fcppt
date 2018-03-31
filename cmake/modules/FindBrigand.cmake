find_path(
	BRIGAND_INCLUDE_DIR
	brigand/brigand.hpp
	HINTS
	"${BRIGAND_INCLUDEDIR}"
)

include(
	FindPackageHandleStandardArgs
)

find_package_handle_standard_args(
	BRIGAND
	DEFAULT_MSG
	BRIGAND_INCLUDE_DIR
)

if(
	BRIGAND_FOUND
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
		"${BRIGAND_INCLUDE_DIR}"
	)
endif()

mark_as_advanced(
	BRIGAND_INCLUDE_DIR
)
