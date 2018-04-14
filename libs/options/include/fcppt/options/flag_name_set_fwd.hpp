//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_FLAG_NAME_SET_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_FLAG_NAME_SET_FWD_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/options/name_set.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The set of flag names.

\ingroup fcpptoptions

Each string in this set is expected not to be followed by a value,
e.g. "--foo".
*/
FCPPT_MAKE_STRONG_TYPEDEF(
	fcppt::options::name_set,
	flag_name_set
);

}
}

#endif
