//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/algorithm/append_result.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_append_result
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const result(
		fcppt::algorithm::append_result(
			int_vector{
				1,
				2
			},
			int_vector{
				3,
				4
			}
		)
	);

	int_vector const expected{
		1,
		2,
		3,
		4
	};

	BOOST_CHECK(
		result
		==
		expected
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_append_result_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_unique_ptr_vector;

	int_unique_ptr_vector const result(
		fcppt::algorithm::append_result(
			fcppt::assign::make_container<
				int_unique_ptr_vector
			>(
				fcppt::make_unique_ptr<
					int
				>(
					1
				)
			)(
				fcppt::make_unique_ptr<
					int
				>(
					2
				)
			).move_container()
			,
			fcppt::assign::make_container<
				int_unique_ptr_vector
			>(
				fcppt::make_unique_ptr<
					int
				>(
					3
				)
			)(
				fcppt::make_unique_ptr<
					int
				>(
					4
				)
			).move_container()
		)
	);

	BOOST_REQUIRE_EQUAL(
		result.size(),
		4u
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
}
