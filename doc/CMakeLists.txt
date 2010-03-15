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

make_fcppt_documentation(
	adapted 
	char_type.hpp
	error 
	filesystem 
	format.hpp 
	from_std_wstring.hpp
	from_std_string.hpp
	io
	narrow.hpp
	preprocessor/file.hpp 
	preprocessor/stringize.hpp
	string.hpp 
	text.hpp 
	to_std_wstring.hpp
	to_std_string.hpp
	widen.hpp 
)
make_fcppt_documentation(algorithm algorithm)
make_fcppt_documentation(alignment alignment)
make_fcppt_documentation(assert assert.hpp assert_message.hpp)
make_fcppt_documentation(assign assign)
make_fcppt_documentation(
	casts
	bad_dynamic_cast.hpp
	bad_truncation_check_cast.hpp
	dynamic_cast.hpp
	sn_cast.hpp
	try_dynamic_cast.hpp
	truncation_check_cast.hpp
)
make_fcppt_documentation(chrono chrono)
make_fcppt_documentation(endianness endianness)
make_fcppt_documentation(
	function
	function/object_fwd.hpp
	function/object.hpp
)
make_fcppt_documentation(math math)
make_fcppt_documentation(
	minmax_pair
	minmax_pair_fwd.hpp
	minmax_pair_decl.hpp
	minmax_pair_impl.hpp
	minmax_pair.hpp
	minmax_pair_output.hpp
	invalid_minmax_pair.hpp
)
make_fcppt_documentation(mpl mpl)
make_fcppt_documentation(noncopyable nonassignable.hpp noncopyable.hpp)
make_fcppt_documentation(log log)
make_fcppt_documentation(optional optional.hpp optional_decl.hpp optional_impl.hpp optional_fwd.hpp)
make_fcppt_documentation(signal signal)
make_fcppt_documentation(
	smartpointers
	const_pointer_cast.hpp
	dynamic_pointer_cast.hpp
	make_auto_ptr.hpp
	make_shared_ptr.hpp
	polymorphic_pointer_cast.hpp
	scoped_ptr_fwd.hpp
	scoped_ptr_decl.hpp
	scoped_ptr_impl.hpp
	scoped_ptr.hpp
	shared_ptr_fwd.hpp
	shared_ptr_decl.hpp
	shared_ptr_impl.hpp
	shared_ptr.hpp
	static_pointer_cast.hpp
	weak_ptr_fwd.hpp
	weak_ptr.hpp
)
make_fcppt_documentation(variant variant)
make_fcppt_documentation(
	visibility
	class_symbol.hpp
	import_symbol.hpp
	export_symbol.hpp
)
make_fcppt_documentation(type_traits type_traits)

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
