//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/pop_front.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <deque>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_pop_front
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::deque<
		int
	>
	int_queue;

	int_queue empty{};

	BOOST_CHECK(
		!fcppt::container::pop_front(
			empty
		).has_value()
	);

	int_queue vec12{
		1,
		2
	};

	BOOST_CHECK_EQUAL(
		fcppt::container::pop_front(
			vec12
		),
		fcppt::optional::make(
			1
		)
	);

	int_queue const expected{
		2
	};

	BOOST_CHECK(
		vec12
		==
		expected
	);
}
