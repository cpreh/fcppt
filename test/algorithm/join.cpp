//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/algorithm/join.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_join_vector
)
{
FCPPT_PP_POP_WARNING

	typedef std::vector<
		int
	> int_vector;

	int_vector const vec3{
		5,
		6
	};

	int_vector const result(
		fcppt::algorithm::join(
			int_vector{
				1,
				2
			},
			int_vector{
				3,
				4
			},
			vec3
		)
	);

	BOOST_REQUIRE_EQUAL(
		result.size(),
		6u
	);

	BOOST_CHECK_EQUAL(
		result[0],
		1
	);

	BOOST_CHECK_EQUAL(
		result[1],
		2
	);

	BOOST_CHECK_EQUAL(
		result[2],
		3
	);

	BOOST_CHECK_EQUAL(
		result[3],
		4
	);

	BOOST_CHECK_EQUAL(
		result[4],
		5
	);

	BOOST_CHECK_EQUAL(
		result[5],
		6
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_join_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_unique_ptr_vector;

	int_unique_ptr_vector const result(
		fcppt::algorithm::join(
			fcppt::assign::make_container<
				int_unique_ptr_vector
			>(
				fcppt::make_unique_ptr<
					int
				>(
					1
				),
				fcppt::make_unique_ptr<
					int
				>(
					2
				)
			),
			fcppt::assign::make_container<
				int_unique_ptr_vector
			>(
				fcppt::make_unique_ptr<
					int
				>(
					3
				),
				fcppt::make_unique_ptr<
					int
				>(
					4
				)
			),
			fcppt::assign::make_container<
				int_unique_ptr_vector
			>(
				fcppt::make_unique_ptr<
					int
				>(
					5
				),
				fcppt::make_unique_ptr<
					int
				>(
					6
				)
			)
		)
	);

	BOOST_REQUIRE_EQUAL(
		result.size(),
		6u
	);

	BOOST_CHECK_EQUAL(
		*result[0],
		1
	);

	BOOST_CHECK_EQUAL(
		*result[1],
		2
	);

	BOOST_CHECK_EQUAL(
		*result[2],
		3
	);

	BOOST_CHECK_EQUAL(
		*result[3],
		4
	);

	BOOST_CHECK_EQUAL(
		*result[4],
		5
	);

	BOOST_CHECK_EQUAL(
		*result[5],
		6
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_join_map
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::map<
		int,
		char
	>
	int_map;

	int_map result(
		fcppt::algorithm::join(
			int_map{
				std::make_pair(
					1,
					'a'
				),
				std::make_pair(
					2,
					'b'
				)
			},
			int_map{
				std::make_pair(
					2,
					'c'
				),
				std::make_pair(
					3,
					'd'
				)
			}
		)
	);

	BOOST_CHECK(
		result.find(
			4
		)
		==
		result.end()
	);

	BOOST_CHECK_EQUAL(
		result[1],
		'a'
	);

	BOOST_CHECK_EQUAL(
		result[2],
		'b'
	);

	BOOST_CHECK_EQUAL(
		result[3],
		'd'
	);
}
