//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STATIC_ASSERT_STATEMENT_HPP_INCLUDED
#define FCPPT_STATIC_ASSERT_STATEMENT_HPP_INCLUDED

#include <fcppt/detail/static_assert_failure.hpp>
#include <fcppt/detail/static_assert_test.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/cat.hpp>
#include <fcppt/config/external_end.hpp>


/**
\brief Assert at compile time that a condition is true, using a statement

\ingroup fcpptvarious

This macro asserts at compile that \a cond is true, using a statement. It must
be used whenever an expression is not allowed.
*/
#define FCPPT_STATIC_ASSERT_STATEMENT(\
	cond\
)\
typedef \
::fcppt::detail::static_assert_test<\
	sizeof(\
		::fcppt::detail::static_assert_failure<\
			static_cast<\
				bool\
			>(\
				cond\
			)\
		>\
	)\
>\
BOOST_PP_CAT(\
	fcppt_static_assert_typedef_,\
	__LINE__\
)

#endif
