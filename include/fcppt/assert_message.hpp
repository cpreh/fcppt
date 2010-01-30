//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_MESSAGE_HPP_INCLUDED

#include <fcppt/detail/process_assert.hpp>
#include <fcppt/preprocessor/stringize.hpp>
#include <fcppt/preprocessor/file.hpp>

/**
 * @brief Runtime assert macro that throws an exception with an additional message
*/
#define FCPPT_ASSERT_MESSAGE(cond, message)\
if (!(cond))\
	fcppt::detail::process_assert(\
		FCPPT_PP_FILE,\
		FCPPT_PP_STRINGIZE(__LINE__),\
		FCPPT_PP_STRINGIZE(cond),\
		message\
	);

#endif
