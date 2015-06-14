//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_comparison.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/optional_output.hpp>
#include <fcppt/container/at_optional.hpp>
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
	fcppt::optional<
		int
	>
	optional_int;

	BOOST_CHECK_EQUAL(
		optional_int(
			fcppt::container::at_optional(
				int_vector,
				1
			)
		),
		optional_int(
			2
		)
	);

	BOOST_CHECK_EQUAL(
		optional_int(
			fcppt::container::at_optional(
				int_vector,
				2
			)
		),
		optional_int()
	);
}
