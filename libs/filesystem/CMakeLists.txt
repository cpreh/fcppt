fcppt_utils_load_source_files(libs/filesystem/files.txt FCPPT_FILESYSTEM_FILES)

make_fcppt_library(
  filesystem
  "${FCPPT_FILESYSTEM_FILES}"
  HAS_IMPL_DIR
  FCPPT_DEPS
  fcppt_core
  TRANSITIVE_FCPPT_DEPS
  fcppt_core_interface)
