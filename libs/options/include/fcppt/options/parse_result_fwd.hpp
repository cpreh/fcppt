//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_PARSE_RESULT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_RESULT_FWD_HPP_INCLUDED

#include <fcppt/either/object_fwd.hpp>
#include <fcppt/options/parse_error_fwd.hpp>
#include <fcppt/options/state_with_value_fwd.hpp>

namespace fcppt
{
namespace options
{
/**
\brief The result of a parser.

\ingroup fcpptoptions

On success, a parser returns a value and the remaining state.
*/
template <typename T>
using parse_result =
    fcppt::either::object<fcppt::options::parse_error, fcppt::options::state_with_value<T>>;

}
}

#endif
