//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_OPERATORS_HPP_INCLUDED
#define FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_OPERATORS_HPP_INCLUDED

#include <fcppt/detail/strong_typedef/foreach_assignment_operator.hpp>
#include <fcppt/detail/strong_typedef/foreach_inc_dec_operator.hpp>
#include <fcppt/detail/strong_typedef/friend_assignment_operator.hpp>
#include <fcppt/detail/strong_typedef/friend_pre_inc_dec_operator.hpp>


#define FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_OPERATORS \
FCPPT_DETAIL_STRONG_TYPEDEF_FOREACH_ASSIGNMENT_OPERATOR(\
	FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_ASSIGNMENT_OPERATOR\
)\
FCPPT_DETAIL_STRONG_TYPEDEF_FOREACH_INC_DEC_OPERATOR(\
	FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_PRE_INC_DEC_OPERATOR\
)

#endif
