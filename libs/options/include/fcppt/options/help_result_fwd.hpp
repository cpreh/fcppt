//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_HELP_RESULT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_HELP_RESULT_FWD_HPP_INCLUDED

#include <fcppt/options/help_text_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/variant/object_fwd.hpp>

namespace fcppt::options
{
/**
\brief The result of invoking a regular parser and a help parser.

\ingroup fcpptoption

A help result is either a regular result or a help text.
*/
template <typename Result>
using help_result =
    fcppt::variant::object<fcppt::options::result<Result>, fcppt::options::help_text>;

}

#endif
