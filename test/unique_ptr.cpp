//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unique_ptr_impl.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(unique_ptr)
{
	typedef fcppt::unique_ptr<
		int
	> int_ptr;

	int_ptr foo(new int(42));
}
