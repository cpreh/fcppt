//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/assign.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	optional_assign
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	optional_int test;

	int const &result(
		fcppt::optional::assign(
			test,
			42
		)
	);

	BOOST_CHECK_EQUAL(
		result,
		42
	);
}

BOOST_AUTO_TEST_CASE(
	optional_assign_move
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	optional_int_unique_ptr test;

	int_unique_ptr const &result(
		fcppt::optional::assign(
			test,
			fcppt::make_unique_ptr<
				int
			>(
				42
			)
		)
	);

	BOOST_CHECK_EQUAL(
		*result,
		42
	);
}
