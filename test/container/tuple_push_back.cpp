//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/tuple_push_back.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	tuple_push_back
)
{
	typedef
	std::tuple<
		int,
		bool
	>
	source_tuple;

	typedef
	std::tuple<
		int,
		bool,
		std::string
	>
	result_tuple;

	result_tuple const result{
		fcppt::container::tuple_push_back(
			source_tuple{
				1,
				false
			},
			std::string{
				"test"
			}
		)
	};

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
		false
	);

	BOOST_CHECK_EQUAL(
		std::get<
			2
		>(
			result
		),
		std::string{
			"test"
		}
	);
}

BOOST_AUTO_TEST_CASE(
	tuple_push_back_move
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	std::tuple<
		int_unique_ptr,
		int_unique_ptr
	> const result(
		fcppt::container::tuple_push_back(
			std::tuple<
				int_unique_ptr
			>{
				fcppt::make_unique_ptr<
					int
				>(
					1
				)
			},
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
