//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_HPP_INCLUDED
#define FCPPT_ASSERT_HPP_INCLUDED

#include <fcppt/preprocessor/stringize.hpp>
#include <fcppt/preprocessor/file.hpp>
#include <fcppt/preprocessor/function.hpp>
#include <fcppt/assertion_failed.hpp>

/// Runtime assert macro that throws fcppt::assertion_failed if the condition does not hold
#define FCPPT_ASSERT(cond)\
if (!(cond))\
	throw fcppt::assertion_failed(\
		FCPPT_PP_FILE,\
		__LINE__,\
		FCPPT_PP_FUNCTION,\
		FCPPT_PP_STRINGIZE(cond),\
		FCPPT_PP_STRINGIZE("")\
	)

#endif
