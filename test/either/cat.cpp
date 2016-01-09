//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/either/cat.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	either_cat
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_int;

	typedef
	std::vector<
		either_int
	>
	either_int_vector;

	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	fcppt::either::object<
		std::string,
		int_vector
	>
	result_type;

	either_int_vector const eithers1{
		either_int{
			42
		},
		either_int{
			std::string(
				"failure"
			)
		},
		either_int{
			10
		},
		either_int{
			std::string(
				"failure2"
			)
		}
	};

	BOOST_CHECK(
		fcppt::either::cat<
			int_vector
		>(
			eithers1
		)
		==
		result_type(
			std::string(
				"failure"
			)
		)
	);

	either_int_vector const eithers2{
		either_int{
			10
		},
		either_int{
			20
		}
	};

	result_type const result(
		fcppt::either::cat<
			int_vector
		>(
			eithers2
		)
	);

	BOOST_CHECK(
		result
		==
		result_type(
			int_vector{
				10,
				20
			}
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	either_cat_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::either::object<
		std::string,
		int_unique_ptr
	>
	either_int;

	typedef
	std::vector<
		either_int
	>
	either_int_vector;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_vector;

	typedef
	fcppt::either::object<
		std::string,
		int_vector
	>
	result_type;

	result_type const result(
		fcppt::either::cat<
			int_vector
		>(
			fcppt::assign::make_container<
				either_int_vector
			>(
				either_int{
					fcppt::make_unique_ptr<
						int
					>(
						10
					)
				}
			)(
				either_int{
					fcppt::make_unique_ptr<
						int
					>(
						20
					)
				}
			)
			.move_container()
		)
	);

	BOOST_REQUIRE(
		result.has_success()
	);

	BOOST_REQUIRE_EQUAL(
		result.get_success_unsafe().size(),
		2u
	);

	BOOST_CHECK_EQUAL(
		*result.get_success_unsafe()[0],
		10
	);

	BOOST_CHECK_EQUAL(
		*result.get_success_unsafe()[1],
		20
	);
}
