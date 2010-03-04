FIND_PACKAGE(Doxygen REQUIRED)

SET(QUICKBOOK_COMMAND "quickbook-${Boost_LIB_VERSION}") # FIXME!

SET(XSLT_COMMAND "xsltproc") # FIXME!

SET(BOOSTBOOK_STYLESHEETS "/usr/share/boostbook-${Boost_LIB_VERSION}/xsl")

SET(DOC_OUTPUT ${CMAKE_BINARY_DIR}/doc_generated)

CONFIGURE_FILE(Doxyfile.in ${CMAKE_SOURCE_DIR}/Doxyfile @ONLY IMMEDIATE)

ADD_CUSTOM_TARGET(
	doc
	COMMAND ${DOXYGEN_EXECUTABLE}
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

ADD_CUSTOM_COMMAND(
	TARGET doc
	COMMAND ${XSLT_COMMAND}
	ARGS
		--xinclude
		-o ${DOC_OUTPUT}/doxygen.xml
		--path ${DOC_OUTPUT}
		${BOOSTBOOK_STYLESHEETS}/doxygen/collect.xsl
		${DOC_OUTPUT}/xml/index.xml
	COMMAND ${XSLT_COMMAND}
	ARGS
		--xinclude
		-o ${DOC_OUTPUT}/doxygen_boostbook.xml
		--path ${DOC_OUTPUT}
		${BOOSTBOOK_STYLESHEETS}/doxygen/doxygen2boostbook.xsl
		${DOC_OUTPUT}/doxygen.xml
	COMMAND ${QUICKBOOK_COMMAND}
	ARGS
		${CMAKE_SOURCE_DIR}/doc/main.qbk
		--output-file ${DOC_OUTPUT}/main.xml
	COMMAND ${XSLT_COMMAND}
		--xinclude
		-o ${DOC_OUTPUT}/main_docbook.xml
		--path ${DOC_OUTPUT}
		${BOOSTBOOK_STYLESHEETS}/docbook.xsl
		${DOC_OUTPUT}/main.xml
	COMMAND ${XSLT_COMMAND}
	ARGS
		--xinclude
		-o ${DOC_OUTPUT}/"html/"
		--path ${DOC_OUTPUT}
		${BOOSTBOOK_STYLESHEETS}/html.xsl
		${DOC_OUTPUT}/main_docbook.xml
	WORKING_DIRECTORY ${DOC_OUTPUT}
)
