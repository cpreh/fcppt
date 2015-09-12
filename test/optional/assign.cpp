//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_assign.hpp>
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
	optional_assign
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional<
		int
	>
	optional_int;

	optional_int test;

	int const &result(
		fcppt::optional_assign(
			test,
			42
		)
	);

	BOOST_CHECK_EQUAL(
		result,
		42
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_assign_move
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

	optional_int_unique_ptr test;

	int_unique_ptr const &result(
		fcppt::optional_assign(
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
