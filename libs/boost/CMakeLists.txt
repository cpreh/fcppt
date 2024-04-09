fcppt_utils_load_source_files(libs/boost/files.txt FCPPT_BOOST_FILES)

make_fcppt_library(
  boost
  "${FCPPT_BOOST_FILES}"
  IS_INTERFACE
  SYSTEM_INCLUDE_DIRS
  ${Boost_INCLUDE_DIRS}
  FCPPT_DEPS
  fcppt_core_interface
  TRANSITIVE_FCPPT_DEPS
  fcppt_core_interface)
