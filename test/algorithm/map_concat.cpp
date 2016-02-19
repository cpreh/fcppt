//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/algorithm/map_concat.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::unique_ptr<
	int
>
int_unique_ptr;

typedef
std::vector<
	int
>
int_vector;

typedef
std::vector<
	int_unique_ptr
>
int_unique_ptr_vector;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map_concat
)
{
FCPPT_PP_POP_WARNING

	int_unique_ptr_vector const ptrs{
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
		)
		.move_container()
	};

	int_vector const result(
		fcppt::algorithm::map_concat<
			int_vector
		>(
			ptrs,
			[](
				int_unique_ptr const &_value
			)
			{
				return
					int_vector{
						*_value,
						*_value + 5
					};
			}
		)
	);

	BOOST_REQUIRE_EQUAL(
		result.size(),
		4u
	);

	BOOST_CHECK_EQUAL(
		result[0],
		1
	);

	BOOST_CHECK_EQUAL(
		result[1],
		6
	);

	BOOST_CHECK_EQUAL(
		result[2],
		2
	);

	BOOST_CHECK_EQUAL(
		result[3],
		7
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map_concat_move
)
{
FCPPT_PP_POP_WARNING

	int_vector const ints{
		1,
		2
	};

	int_unique_ptr_vector const result(
		fcppt::algorithm::map_concat<
			int_unique_ptr_vector
		>(
			ints,
			[](
				int const _value
			)
			{
				return
					fcppt::assign::make_container<
						int_unique_ptr_vector
					>(
						fcppt::make_unique_ptr<
							int
						>(
							_value
						)
					)(
						fcppt::make_unique_ptr<
							int
						>(
							_value + 5
						)
					).move_container();
			}
		)
	);

	BOOST_REQUIRE_EQUAL(
		result.size(),
		4
	);

	BOOST_CHECK_EQUAL(
		*result[0],
		1
	);

	BOOST_CHECK_EQUAL(
		*result[1],
		6
	);

	BOOST_CHECK_EQUAL(
		*result[2],
		2
	);

	BOOST_CHECK_EQUAL(
		*result[3],
		7
	);
}
