//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_ASSIGNMENT_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_ASSIGNMENT_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/detail/strong_typedef/assignment_operator.hpp>
#include <fcppt/detail/strong_typedef/foreach_assignment_operator.hpp>


namespace fcppt
{

FCPPT_DETAIL_STRONG_TYPEDEF_FOREACH_ASSIGNMENT_OPERATOR(
	FCPPT_DETAIL_STRONG_TYPEDEF_ASSIGNMENT_OPERATOR
)

}

#endif
