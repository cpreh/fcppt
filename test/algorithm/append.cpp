//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/algorithm/append.hpp>
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
	append_copy
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector ints{
		1,2,3
	};

	fcppt::algorithm::append(
		ints,
		int_vector{
			4,5,6
		}
	);

	int_vector const result{
		1,2,3,4,5,6
	};

	BOOST_CHECK(
		ints
		==
		result
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	append_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		fcppt::unique_ptr<
			int
		>
	>
	int_ptr_vector;

	int_ptr_vector ints;

	ints.push_back(
		fcppt::make_unique_ptr<
			int
		>(
			1
		)
	);

	ints.push_back(
		fcppt::make_unique_ptr<
			int
		>(
			2
		)
	);

	fcppt::algorithm::append(
		ints,
		[]{
			int_ptr_vector new_ints;

			new_ints.push_back(
				fcppt::make_unique_ptr<
					int
				>(
					3
				)
			);

			new_ints.push_back(
				fcppt::make_unique_ptr<
					int
				>(
					4
				)
			);

			return
				new_ints;
		}()
	);

	BOOST_REQUIRE_EQUAL(
		ints.size(),
		4u
	);

	BOOST_CHECK_EQUAL(
		*ints[0],
		1
	);

	BOOST_CHECK_EQUAL(
		*ints[1],
		2
	);

	BOOST_CHECK_EQUAL(
		*ints[2],
		3
	);

	BOOST_CHECK_EQUAL(
		*ints[3],
		4
	);
}
