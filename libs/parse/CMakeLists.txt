fcppt_utils_load_source_files(libs/parse/files.txt FCPPT_PARSE_FILES)

make_fcppt_library(
  parse
  "${FCPPT_PARSE_FILES}"
  IS_INTERFACE
  FCPPT_DEPS
  fcppt_core_interface
  TRANSITIVE_FCPPT_DEPS
  fcppt_core_interface)
