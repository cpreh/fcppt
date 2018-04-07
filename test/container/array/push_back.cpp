//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/array/make.hpp>
#include <fcppt/container/array/push_back.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	array_push_back
)
{
	typedef
	std::array<
		int,
		3
	>
	int3_array;

	typedef
	std::array<
		int,
		4
	>
	int4_array;

	int3_array const test{{
		1,
		2,
		3
	}};

	int4_array const result(
		fcppt::container::array::push_back(
			test,
			4
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			result
		),
		1
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			result
		),
		2
	);

	BOOST_CHECK_EQUAL(
		std::get<
			2
		>(
			result
		),
		3
	);

	BOOST_CHECK_EQUAL(
		std::get<
			3
		>(
			result
		),
		4
	);
}

BOOST_AUTO_TEST_CASE(
	array_push_back_move
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	std::array<
		int_unique_ptr,
		2
	> const result(
		fcppt::container::array::push_back(
			fcppt::container::array::make(
				fcppt::make_unique_ptr<
					int
				>(
					1
				)
			),
			fcppt::make_unique_ptr<
				int
			>(
				2
			)
		)
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			0
		>(
			result
		),
		1
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			1
		>(
			result
		),
		2
	);
}
