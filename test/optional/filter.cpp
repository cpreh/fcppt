//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_filter.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_filter
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional<
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
		fcppt::optional_filter(
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
		fcppt::optional_filter(
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
		fcppt::optional_filter(
			optional_int(),
			function
		)
	);

	BOOST_CHECK(
		!result3.has_value()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_filter_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	optional_int_unique_ptr const result(
		fcppt::optional_filter(
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
