//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_OPTIONAL_ERROR_HPP_INCLUDED
#define FCPPT_ASSERT_OPTIONAL_ERROR_HPP_INCLUDED

#include <fcppt/absurd.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/basic/print_message.hpp>


/**
\brief Asserts that an optional is not nothing or returns its contents

\ingroup fcpptassert

If \a opt is nothing, <code>std::terminate</code> is called. Otherwise, the
result of the macro is <code>opt.get_unsafe()</code>.
*/
#define FCPPT_ASSERT_OPTIONAL_ERROR(\
	opt\
)\
(\
(opt) \
? \
	(opt).get_unsafe() \
: \
	(\
		FCPPT_ASSERT_BASIC_PRINT_MESSAGE(\
			(opt),\
			FCPPT_TEXT("")\
		),\
		fcppt::absurd<\
			decltype(\
				(opt).get_unsafe()\
			)\
		>()\
	)\
)

#endif
