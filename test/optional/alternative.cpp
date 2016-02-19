//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/alternative.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_alternative
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	BOOST_CHECK_EQUAL(
		fcppt::optional::alternative(
			optional_int(
				42
			),
			optional_int(
				10
			)
		),
		optional_int(
			42
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::alternative(
			optional_int(),
			optional_int(
				10
			)
		),
		optional_int(
			10
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::alternative(
			optional_int(),
			optional_int()
		),
		optional_int()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_alternative_move
)
{
FCPPT_PP_POP_WARNING

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

	BOOST_CHECK(
		fcppt::optional::maybe(
			fcppt::optional::alternative(
				optional_int_unique_ptr(
					fcppt::make_unique_ptr<
						int
					>(
						42
					)
				),
				optional_int_unique_ptr()
			),
			fcppt::const_(
				false
			),
			[](
				int_unique_ptr const &_ptr
			)
			{
				return
					*_ptr
					==
					42;
			}
		)
	);
}
