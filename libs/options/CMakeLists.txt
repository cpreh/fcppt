fcppt_utils_load_source_files(libs/options/files.txt FCPPT_OPTIONS_FILES)

make_fcppt_library(
  options
  "${FCPPT_OPTIONS_FILES}"
  HAS_IMPL_DIR
  FCPPT_DEPS
  fcppt_core
  TRANSITIVE_FCPPT_DEPS
  fcppt_core_interface)
