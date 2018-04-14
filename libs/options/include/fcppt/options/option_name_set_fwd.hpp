//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTION_NAME_SET_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_NAME_SET_FWD_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/options/name_set.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The set of option names.

\ingroup fcpptoptions

Each string in this set is expected to be followed by a value,
e.g. "--foo bar".
*/
FCPPT_MAKE_STRONG_TYPEDEF(
	fcppt::options::name_set,
	option_name_set
);

}
}

#endif
