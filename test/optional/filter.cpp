//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/filter.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	optional_filter
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	auto const function(
		[](
			int const _value
		)
		{
			return
				_value
				==
				42;
		}
	);

	optional_int const result1(
		fcppt::optional::filter(
			optional_int(
				42
			),
			function
		)
	);

	BOOST_REQUIRE(
		result1.has_value()
	);

	BOOST_CHECK_EQUAL(
		result1.get_unsafe(),
		42
	);

	optional_int const result2(
		fcppt::optional::filter(
			optional_int(
				10
			),
			function
		)
	);

	BOOST_CHECK(
		!result2.has_value()
	);

	optional_int const result3(
		fcppt::optional::filter(
			optional_int(),
			function
		)
	);

	BOOST_CHECK(
		!result3.has_value()
	);
}

BOOST_AUTO_TEST_CASE(
	optional_filter_move
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

	optional_int_unique_ptr const result(
		fcppt::optional::filter(
			optional_int_unique_ptr(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			),
			[](
				int_unique_ptr const &_value
			)
			{
				return
					*_value
					==
					42;
			}
		)
	);

	BOOST_REQUIRE(
		result.has_value()
	);

	BOOST_CHECK_EQUAL(
		*result.get_unsafe(),
		42
	);
}
