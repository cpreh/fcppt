//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_NAME_SET_HPP_INCLUDED
#define FCPPT_OPTIONS_NAME_SET_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A set of flag and/or option names.

\ingroup fcpptoptions
*/
typedef
std::unordered_set<
	fcppt::string
>
name_set;

}
}

#endif
