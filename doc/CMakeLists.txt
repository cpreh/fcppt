FIND_PACKAGE(Doxygen REQUIRED)
FIND_PACKAGE(Xsltproc REQUIRED)

SET(QUICKBOOK_VERSION ${Boost_LIB_VERSION})

FIND_PACKAGE(Quickbook REQUIRED)

SET(DOC_OUTPUT ${CMAKE_BINARY_DIR}/doc_generated)

FILE(COPY xsl/ DESTINATION ${DOC_OUTPUT}/xsl)

SET(BOOSTBOOK_STYLESHEETS ${DOC_OUTPUT}/xsl)

ADD_CUSTOM_TARGET(
	doc
)

CONFIGURE_FILE(xsl/docbook.xsl.in ${DOC_OUTPUT}/xsl/docbook.xsl IMMEDIATE)

MACRO(make_fcppt_documentation name)
	#	SET(DOXYGEN_INPUT_PATH ${ARGN})
	SET(DOXYGEN_INPUT_PATH)
	SET(DOXYGEN_CURRENT_FILE ${DOC_OUTPUT}/${name}.doxyfile)

	FOREACH(arg ${ARGN})
		SET(DOXYGEN_INPUT_PATH "${DOXYGEN_INPUT_PATH} ${CMAKE_SOURCE_DIR}/include/fcppt/${arg}")
	ENDFOREACH(arg)

	CONFIGURE_FILE(Doxyfile.in ${DOXYGEN_CURRENT_FILE} @ONLY IMMEDIATE)

	ADD_CUSTOM_COMMAND(
		TARGET doc
		COMMAND ${DOXYGEN_EXECUTABLE}
		ARGS
			${DOXYGEN_CURRENT_FILE}
		COMMAND ${XSLTPROC_EXECUTABLE}
		ARGS
			--xinclude
			-o ${DOC_OUTPUT}/doxygen.xml
			--path ${DOC_OUTPUT}
			${BOOSTBOOK_STYLESHEETS}/doxygen/collect.xsl
			${DOC_OUTPUT}/xml/index.xml
		COMMAND ${XSLTPROC_EXECUTABLE}
		ARGS
			--xinclude
			-o ${DOC_OUTPUT}/doxygen_${name}.xml
			--path ${DOC_OUTPUT}
			${BOOSTBOOK_STYLESHEETS}/doxygen/doxygen2boostbook.xsl
			${DOC_OUTPUT}/doxygen.xml)
ENDMACRO(make_fcppt_documentation)

make_fcppt_documentation(adapted filesystem error format.hpp io preprocessor/file.hpp text.hpp string.hpp )
make_fcppt_documentation(algorithm algorithm)
make_fcppt_documentation(alignment alignment)
make_fcppt_documentation(assert assert.hpp assert_message.hpp)
make_fcppt_documentation(assign assign)
make_fcppt_documentation(chrono chrono)
make_fcppt_documentation(endianness endianness)
make_fcppt_documentation(math math)
make_fcppt_documentation(mpl mpl)
make_fcppt_documentation(noncopyable nonassignable.hpp noncopyable.hpp)
make_fcppt_documentation(log log)
make_fcppt_documentation(optional optional.hpp optional_decl.hpp optional_impl.hpp optional_fwd.hpp)
make_fcppt_documentation(signal signal)
make_fcppt_documentation(variant variant)

ADD_CUSTOM_COMMAND(
	TARGET doc
	COMMAND ${QUICKBOOK_EXECUTABLE}
	ARGS
		${CMAKE_SOURCE_DIR}/doc/main.qbk
		--output-file ${DOC_OUTPUT}/main.xml
	COMMAND ${XSLTPROC_EXECUTABLE}
		--xinclude
		-o ${DOC_OUTPUT}/main_docbook.xml
		--path ${DOC_OUTPUT}
		${BOOSTBOOK_STYLESHEETS}/docbook.xsl
		${DOC_OUTPUT}/main.xml
	COMMAND ${XSLTPROC_EXECUTABLE}
	ARGS
		--xinclude
		-o ${DOC_OUTPUT}/"html/"
		--path ${DOC_OUTPUT}
		${BOOSTBOOK_STYLESHEETS}/html.xsl
		${DOC_OUTPUT}/main_docbook.xml
	WORKING_DIRECTORY ${DOC_OUTPUT}
)

FILE(GLOB html_files files/*)
FILE(COPY ${html_files} DESTINATION ${DOC_OUTPUT}/html)

INSTALL(DIRECTORY ${DOC_OUTPUT}/html DESTINATION ${CMAKE_INSTALL_PREFIX}/share/doc/fcppt)
