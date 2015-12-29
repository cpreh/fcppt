//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_apply.hpp>
#include <fcppt/optional_comparison.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/optional_output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_apply
)
{
FCPPT_PP_POP_WARNING
	typedef
	fcppt::optional<
		int
	>
	optional_int;

	typedef
	fcppt::optional<
		unsigned
	>
	optional_unsigned;

	typedef
	fcppt::optional<
		std::string
	>
	optional_string;

	BOOST_CHECK_EQUAL(
		fcppt::optional_apply(
			[](
				int const _val1,
				unsigned const _val2
			)
			{
				return
					std::to_string(
						_val1
					)
					+
					std::to_string(
						_val2
					);
			},
			optional_int(
				10
			),
			optional_unsigned(
				20u
			)
		),
		optional_string(
			std::string(
				"1020"
			)
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional_apply(
			[](
				int,
				unsigned
			)
			{
				return
					std::string{};
			},
			optional_int(),
			optional_unsigned(
				20
			)
		),
		optional_string()
	);
}
