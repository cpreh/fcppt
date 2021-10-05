//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_LONG_NAME_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_LONG_NAME_FWD_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/string.hpp>

namespace fcppt::options
{
/**
\brief A string type representing a long name.

\ingroup fcpptoptions

A long name is the name of an argument, e.g. "arg", or the long name of an
option or flag, e.g. "--foo".
*/
FCPPT_DECLARE_STRONG_TYPEDEF(fcppt::string, long_name);

}

#endif
