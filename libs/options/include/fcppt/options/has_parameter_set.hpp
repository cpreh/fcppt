//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_HAS_PARAMETER_SET_HPP_INCLUDED
#define FCPPT_OPTIONS_HAS_PARAMETER_SET_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

typedef
std::unordered_set<
	fcppt::string
>
has_parameter_set;

}
}

#endif
