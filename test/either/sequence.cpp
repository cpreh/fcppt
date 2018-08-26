//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::sequence",
	"[either]"
)
{
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

	SECTION(
		"Test failure sequence"
	)
	{
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

		result_type const result{
			fcppt::either::sequence<
				int_vector
			>(
				eithers1
			)
		};

		REQUIRE(
			result.has_failure()
		);

		CHECK(
			result.get_failure_unsafe()
			==
			std::string(
				"failure"
			)
		);
	}

	SECTION(
		"Test success sequence"
	)
	{
		either_int_vector const eithers2{
			either_int{
				10
			},
			either_int{
				20
			}
		};

		result_type const result(
			fcppt::either::sequence<
				int_vector
			>(
				eithers2
			)
		);

		REQUIRE(
			result.has_success()
		);

		CHECK(
			result.get_success_unsafe()
			==
			int_vector{
				10,
				20
			}
		);
	}
}

TEST_CASE(
	"either::sequence move",
	"[either]"
)
{
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
		fcppt::either::sequence<
			int_vector
		>(
			fcppt::container::make<
				either_int_vector
			>(
				either_int{
					fcppt::make_unique_ptr<
						int
					>(
						10
					)
				},
				either_int{
					fcppt::make_unique_ptr<
						int
					>(
						20
					)
				}
			)
		)
	);

	REQUIRE(
		result.has_success()
	);

	REQUIRE(
		result.get_success_unsafe().size()
		==
		2u
	);

	CHECK(
		*result.get_success_unsafe()[0]
		==
		10
	);

	CHECK(
		*result.get_success_unsafe()[1]
		==
		20
	);
}
