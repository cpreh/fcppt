//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_THROW_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_THROW_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/conditional.hpp>
#include <fcppt/assert/gather_information.hpp>


#define FCPPT_ASSERT_THROW_MESSAGE(\
	condition,\
	exception,\
	message\
) \
FCPPT_ASSERT_CONDITIONAL(\
	condition,\
	throw exception(\
		FCPPT_ASSERT_GATHER_INFORMATION(\
			condition,\
			message\
		)\
	) \
)

#endif
