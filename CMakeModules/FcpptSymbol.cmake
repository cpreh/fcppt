function(
	fcppt_generate_symbol_header
	STATIC_LINK_FLAG
	EXPORTS_NAME
	SYMBOL_NAME
	RELATIVE_PATH
)
	set(
		SYMBOL_NAME_LONG
		"${SYMBOL_NAME}_SYMBOL"
	)

	set(
		BINARY_DIR
		"${${PROJECT_NAME}_BINARY_DIR}"
	)

	set(
		TEMP_FILE
		"${BINARY_DIR}/fcppt_generate_symbol.hpp.in"
	)

	file(
		WRITE
		"${TEMP_FILE}"
"
#ifndef ${SYMBOL_NAME_LONG}_HPP_INCLUDED
#define ${SYMBOL_NAME_LONG}_HPP_INCLUDED

#if defined(${STATIC_LINK_FLAG})
#	define ${SYMBOL_NAME_LONG}
#elif defined(${EXPORTS_NAME}_EXPORTS)
#	include <fcppt/export_symbol.hpp>
#	define ${SYMBOL_NAME_LONG} FCPPT_EXPORT_SYMBOL
#else
#	include <fcppt/import_symbol.hpp>
#	define ${SYMBOL_NAME_LONG} FCPPT_IMPORT_SYMBOL
#endif

#endif
"
	)

	configure_file(
		"${TEMP_FILE}"
		"${BINARY_DIR}/include/${RELATIVE_PATH}/symbol.hpp"
	)
endfunction()
