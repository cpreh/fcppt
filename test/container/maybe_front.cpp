//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional.hpp>
#include <fcppt/optional_output.hpp>
#include <fcppt/container/maybe_front.hpp>
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
	container_maybe_front
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	fcppt::optional<
		int
	>
	optional_int;

	int_vector const empty{};

	BOOST_CHECK(
		!fcppt::container::maybe_front(
			empty
		).has_value()
	);

	int_vector const vec12{
		1,
		2
	};

	BOOST_CHECK_EQUAL(
		optional_int(
			fcppt::container::maybe_front(
				vec12
			)
		),
		optional_int(
			1
		)
	);
}
