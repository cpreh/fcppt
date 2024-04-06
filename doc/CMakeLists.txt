find_package(Doxygen REQUIRED)

set(DOC_OUTPUT "${FCPPT_UTILS_PROJECT_BINARY_DIR}/doc_generated")

configure_file(Doxyfile.in "${DOC_OUTPUT}/Doxyfile" @ONLY)

configure_file(header.html "${DOC_OUTPUT}/header.html" COPYONLY)

configure_file(footer.html "${DOC_OUTPUT}/footer.html" COPYONLY)

configure_file(stylesheet.css "${DOC_OUTPUT}/stylesheet.css" COPYONLY)

configure_file(layout.xml "${DOC_OUTPUT}/layout.xml" COPYONLY)

file(STRINGS doc_files.txt FCPPT_DOC_FILES)
file(STRINGS all_files.txt FCPPT_ALL_FILES)
list(APPEND FCPPT_DOC_FILES ${FCPPT_ALL_FILES})

fcppt_utils_append_source_dir("${FCPPT_DOC_FILES}" FCPPT_DOC_FILES_ABS)

set(HTML_INDEX_OUTPUT ${DOC_OUTPUT}/html/index.html)

add_custom_command(
  OUTPUT "${HTML_INDEX_OUTPUT}"
  COMMAND ${DOXYGEN_EXECUTABLE}
  DEPENDS ${FCPPT_DOC_FILES_ABS}
  WORKING_DIRECTORY "${DOC_OUTPUT}")

add_custom_target(doc ALL SOURCES ${HTML_INDEX_OUTPUT})

install(DIRECTORY "${DOC_OUTPUT}/html" DESTINATION ${CMAKE_INSTALL_DOCDIR})
