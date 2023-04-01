//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args.hpp>
#include <fcppt/args_char.hpp>
#include <fcppt/args_from_second.hpp>
#include <fcppt/args_vector.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

fcppt::args_vector
fcppt::args_from_second(int const _argc, fcppt::args_char const *const *const _argv)
{
  return _argc == 0 ? fcppt::args_vector{}
                    : fcppt::args(
                          _argc - 1,
                          _argv
                              // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
                              + 1);
}

FCPPT_PP_POP_WARNING
