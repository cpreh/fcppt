//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_UNCONDITIONAL_HPP_INCLUDED
#define FCPPT_ASSERT_UNCONDITIONAL_HPP_INCLUDED

#include <fcppt/assert/print_message.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/empty.hpp>
#include <fcppt/config/external_end.hpp>

#define FCPPT_ASSERT_UNCONDITONAL(\
	message,\
	action\
) \
FCPPT_ASSERT_PRINT_MESSAGE(\
	BOOST_PP_EMPTY,\
	message\
); \
action ; \

#endif
