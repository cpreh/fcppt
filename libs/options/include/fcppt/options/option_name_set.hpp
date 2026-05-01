//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_OPTION_NAME_SET_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_NAME_SET_HPP_INCLUDED

#include <fcppt/options/option_name.hpp>
#include <fcppt/options/detail/option_name_equal.hpp>
#include <fcppt/options/detail/option_name_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
/**
\brief The set of option names.

\ingroup fcpptoptions

Each string in this set is expected to be followed by a value,
e.g. "--foo bar".
*/
using option_name_set = std::unordered_set<
    fcppt::options::option_name,
    fcppt::options::detail::option_name_hash,
    fcppt::options::detail::option_name_equal>;
}

#endif
