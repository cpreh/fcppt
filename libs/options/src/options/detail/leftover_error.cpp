//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/not.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/leftover_error.hpp>
#include <fcppt/options/detail/optional_error.hpp>

fcppt::options::detail::optional_error
fcppt::options::detail::leftover_error(fcppt::options::state const &_state)
{
  return fcppt::optional::make_if(fcppt::not_(_state.empty()), [&_state] {
    return fcppt::options::error{
        FCPPT_TEXT("Leftover arguments ") +
        fcppt::output_to_fcppt_string(fcppt::container::output(_state.args()))};
  });
}
