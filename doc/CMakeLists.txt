find_package(Doxygen REQUIRED)

set(DOC_OUTPUT "${FCPPT_UTILS_PROJECT_BINARY_DIR}/doc_generated")

configure_file(Doxyfile.in "${DOC_OUTPUT}/Doxyfile" @ONLY)

configure_file(header.html "${DOC_OUTPUT}/header.html" COPYONLY)

configure_file(footer.html "${DOC_OUTPUT}/footer.html" COPYONLY)

configure_file(stylesheet.css "${DOC_OUTPUT}/stylesheet.css" COPYONLY)

configure_file(layout.xml "${DOC_OUTPUT}/layout.xml" COPYONLY)

fcppt_utils_load_source_files(doc/doc_files.txt FCPPT_DOC_FILES)
fcppt_utils_load_source_files(doc/all_files.txt FCPPT_ALL_FILES)
list(APPEND FCPPT_DOC_FILES ${FCPPT_ALL_FILES})

fcppt_utils_append_source_dir("${FCPPT_DOC_FILES}" FCPPT_DOC_FILES_ABS)

set(HTML_INDEX_OUTPUT ${DOC_OUTPUT}/html/index.html)

add_custom_command(
  OUTPUT "${HTML_INDEX_OUTPUT}"
  COMMAND ${DOXYGEN_EXECUTABLE}
  DEPENDS ${FCPPT_DOC_FILES_ABS}
  WORKING_DIRECTORY "${DOC_OUTPUT}"
  COMMENT "Generating HTML documentation.")

add_custom_target(doc ALL SOURCES ${HTML_INDEX_OUTPUT} COMMENT "Doc target.")

install(DIRECTORY "${DOC_OUTPUT}/html" DESTINATION ${CMAKE_INSTALL_DOCDIR})
