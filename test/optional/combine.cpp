//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional.hpp>
#include <fcppt/optional_combine.hpp>
#include <fcppt/optional_output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_combine
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional<
		int
	>
	optional_int;

	std::plus<
		int
	> const add{};

	BOOST_CHECK_EQUAL(
		fcppt::optional_combine(
			optional_int(
				10
			),
			optional_int(
				20
			),
			add
		),
		optional_int(
			30
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional_combine(
			optional_int(
				10
			),
			optional_int(),
			add
		),
		optional_int(
			10
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional_combine(
			optional_int(),
			optional_int(
				20
			),
			add
		),
		optional_int(
			20
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional_combine(
			optional_int(),
			optional_int(),
			add
		),
		optional_int()
	);
}
