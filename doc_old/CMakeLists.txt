find_package(
	Doxygen
	REQUIRED
)

set(
	DOC_OUTPUT
	"${CMAKE_BINARY_DIR}/doc_generated"
)

configure_file(
	Doxyfile.in
	"${DOC_OUTPUT}/Doxyfile"
)

# For now, use COPYONLY (since I don't know which escape sequences are in the
# html/css files that cmake might accidentally replace. Could be changed in
# the future.
configure_file(
	header.html
	"${DOC_OUTPUT}/header.html"
	COPYONLY
)

configure_file(
	footer.html
	"${DOC_OUTPUT}/footer.html"
	COPYONLY
)

configure_file(
	stylesheet.css
	"${DOC_OUTPUT}/stylesheet.css"
	COPYONLY
)

configure_file(
	layout.xml
	"${DOC_OUTPUT}/layout.xml"
	COPYONLY
)

add_custom_target(
	doc
)

add_custom_command(
	TARGET doc
	COMMAND ${DOXYGEN_EXECUTABLE}
	WORKING_DIRECTORY "${DOC_OUTPUT}"
)

install(
	DIRECTORY
	"${DOC_OUTPUT}/html"
	DESTINATION
	"${INSTALL_DOC_DIR}"
)
