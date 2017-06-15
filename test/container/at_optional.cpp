//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/container/at_optional.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_at_optional
)
{
FCPPT_PP_POP_WARNING

	std::vector<
		int
	> const int_vector{
		1,
		2
	};

	typedef
	fcppt::optional::reference<
		int const
	>
	optional_int_ref;

	BOOST_CHECK_EQUAL(
		fcppt::container::at_optional(
			int_vector,
			1
		),
		optional_int_ref{
			fcppt::make_cref(
				int_vector[
					1
				]
			)
		}
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::at_optional(
			int_vector,
			2
		),
		optional_int_ref{}
	);
}
