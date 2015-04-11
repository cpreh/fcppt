//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_impl.hpp>
#include <fcppt/optional_ref_compare.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_ref_compare
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional<
		int &
	> optional_int_ref;

	int a = 0;

	int b = 0;

	optional_int_ref const opt_a(
		a
	);

	optional_int_ref const opt_b(
		b
	);

	BOOST_CHECK(
		fcppt::optional_ref_compare(
			opt_a,
			optional_int_ref(
				a
			)
		)
	);

	BOOST_CHECK(
		!fcppt::optional_ref_compare(
			opt_a,
			opt_b
		)
	);

	BOOST_CHECK(
		!fcppt::optional_ref_compare(
			opt_a,
			optional_int_ref()
		)
	);
}
