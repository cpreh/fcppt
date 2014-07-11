//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/algorithm/join_move.hpp>
#include <fcppt/assign/make_container.hpp>
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
	algorithm_join_move
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
		fcppt::algorithm::join_move(
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
			).move_container(),
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
			).move_container(),
			fcppt::assign::make_container<
				int_unique_ptr_vector
			>(
				fcppt::make_unique_ptr<
					int
				>(
					5
				)
			)(
				fcppt::make_unique_ptr<
					int
				>(
					6
				)
			).move_container()
		)
	);

	BOOST_REQUIRE(
		result.size() == 6u
		&& *result[0] == 1
		&& *result[1] == 2
		&& *result[2] == 3
		&& *result[3] == 4
		&& *result[4] == 5
		&& *result[5] == 6
	);
}
