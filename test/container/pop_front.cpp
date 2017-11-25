//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/container/pop_front.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <deque>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_pop_front
)
{
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

BOOST_AUTO_TEST_CASE(
	container_pop_front_move
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_ptr;

	typedef
	std::deque<
		int_ptr
	>
	int_ptr_queue;

	int_ptr_queue queue(
		fcppt::assign::make_container<
			int_ptr_queue
		>(
			fcppt::make_unique_ptr<
				int
			>(
				42
			)
		)
	);

	fcppt::optional::maybe(
		fcppt::container::pop_front(
			queue
		),
		[]{
			BOOST_CHECK(
				false
			);
		},
		[](
			int_ptr &&_ptr
		)
		{
			BOOST_CHECK_EQUAL(
				*_ptr,
				42
			);
		}
	);

	BOOST_CHECK(
		queue.empty()
	);
}
