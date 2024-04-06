file(STRINGS core_files.txt FCPPT_CORE_FILES)

# TODO: clang-tidy 18 crashes on this
set_source_files_properties(src/error/strerrno.cpp PROPERTIES SKIP_LINTING ON)

make_fcppt_library(
  core
  "${FCPPT_CORE_FILES}"
  HAS_IMPL_DIR
  SYMBOL_NAME
  FCPPT
  INCLUDE_DIRS
  ${CORE_INCLUDE_DIRS}
  HEADER_ONLY_EXCEPTIONS
  libs/core/include/fcppt/config/clang_version_at_least.h
  libs/core/include/fcppt/config/compiler.h
  libs/core/include/fcppt/config/external_begin.h
  libs/core/include/fcppt/config/external_begin.hpp
  libs/core/include/fcppt/config/external_end.hpp
  libs/core/include/fcppt/config/external_end.h
  libs/core/include/fcppt/config/detail/clang_version_at_least.h
  libs/core/include/fcppt/config/detail/gcc_version_at_least.h
  libs/core/include/fcppt/config/detail/major_minor_at_least.h
  libs/core/include/fcppt/config/gcc_version_at_least.h
  libs/core/include/fcppt/config/platform.h
  libs/core/include/fcppt/preprocessor/detail/disable_clang_warning.h
  libs/core/include/fcppt/preprocessor/detail/disable_gcc_warning.h
  libs/core/include/fcppt/preprocessor/detail/disable_gnu_gcc_warning.h
  libs/core/include/fcppt/preprocessor/detail/pop_warning.h
  libs/core/include/fcppt/preprocessor/detail/pragma.h
  libs/core/include/fcppt/preprocessor/detail/push_warning.h
  libs/core/include/fcppt/preprocessor/disable_clang_warning.h
  libs/core/include/fcppt/preprocessor/disable_gcc_warning.h
  libs/core/include/fcppt/preprocessor/disable_gnu_gcc_warning.h
  libs/core/include/fcppt/preprocessor/ignore_dangling_reference.h
  libs/core/include/fcppt/preprocessor/ignore_unsafe_buffer_usage.h
  libs/core/include/fcppt/preprocessor/pop_warning.h
  libs/core/include/fcppt/preprocessor/pragma.h
  libs/core/include/fcppt/preprocessor/push_warning.h
  libs/core/include/fcppt/symbol/export.h
  libs/core/include/fcppt/symbol/import.h)
