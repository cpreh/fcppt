//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_FLAG_NAME_SET_HPP_INCLUDED
#define FCPPT_OPTIONS_FLAG_NAME_SET_HPP_INCLUDED

#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep
#include <fcppt/options/flag_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
/**
\brief The set of flag names.

\ingroup fcpptoptions

Each string in this set is expected not to be followed by a value,
e.g. "--foo".
*/
using flag_name_set = std::set<fcppt::options::flag_name>;

}

#endif
