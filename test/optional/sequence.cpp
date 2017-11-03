//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/optional/sequence.hpp>
#include <fcppt/optional/object_impl.hpp>
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
	optional_sequence
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	typedef
	std::vector<
		optional_int
	>
	optional_int_vector;

	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	fcppt::optional::object<
		int_vector
	>
	result_type;

	{
		result_type const result(
			fcppt::optional::sequence<
				int_vector
			>(
				optional_int_vector{
					optional_int{
						10
					},
					optional_int{
						20
					}
				}
			)
		);

		BOOST_REQUIRE(
			result.has_value()
		);

		BOOST_REQUIRE_EQUAL(
			result.get_unsafe()[0],
			10
		);

		BOOST_REQUIRE_EQUAL(
			result.get_unsafe()[1],
			20
		);
	}

	{
		result_type const result2(
			fcppt::optional::sequence<
				int_vector
			>(
				optional_int_vector{
					optional_int{
						10
					},
					optional_int{}
				}
			)
		);

		BOOST_REQUIRE(
			!result2.has_value()
		);
	}
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_sequence_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	typedef
	std::vector<
		optional_int_unique_ptr
	>
	optional_int_unique_ptr_vector;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_unique_ptr_vector;


	typedef
	fcppt::optional::object<
		int_unique_ptr_vector
	>
	result_type;

	result_type const result(
		fcppt::optional::sequence<
			int_unique_ptr_vector
		>(
			fcppt::assign::make_container<
				optional_int_unique_ptr_vector
			>(
				optional_int_unique_ptr(
					fcppt::make_unique_ptr<
						int
					>(
						42
					)
				)
			)
		)
	);

	BOOST_REQUIRE(
		result.has_value()
	);

	BOOST_CHECK_EQUAL(
		*result.get_unsafe()[0],
		42
	);
}
