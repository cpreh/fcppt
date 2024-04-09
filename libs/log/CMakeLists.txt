fcppt_utils_load_source_files(libs/log/files.txt FCPPT_LOG_FILES)

if(ENABLE_THREADS)
  set(FCPPT_LOG_COMPILE_DEFINITIONS "ENABLE_THREADS")
endif()

make_fcppt_library(
  log
  "${FCPPT_LOG_FILES}"
  HAS_IMPL_DIR
  FCPPT_DEPS
  fcppt_core
  TRANSITIVE_FCPPT_DEPS
  fcppt_core_interface
  COMPILE_DEFINITIONS
  ${FCPPT_LOG_COMPILE_DEFINITIONS})
