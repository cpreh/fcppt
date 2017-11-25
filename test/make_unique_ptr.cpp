//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	make_unique_ptr
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_ptr;

	int_ptr test1(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	BOOST_CHECK_EQUAL(
		*test1,
		42
	);
}
