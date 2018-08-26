//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/function_impl.hpp>
#include <fcppt/container/array/make.hpp>
#include <fcppt/either/first_success.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::first_success",
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
	fcppt::function<
		either_int ()
	>
	function_type;

	function_type const f1{
		[]{
			return
				either_int{
					42
				};
		}
	};

	function_type const f2{
		[]{
			return
				either_int{
					std::string{
						"f1"
					}
				};
		}
	};

	function_type const f3{
		[]{
			return
				either_int{
					std::string{
						"f2"
					}
				};
		}
	};

	typedef
	fcppt::either::object<
		std::vector<
			std::string
		>,
		int
	>
	result_type;

	SECTION(
		"test success"
	)
	{
		result_type const result{
			fcppt::either::first_success(
				fcppt::container::array::make(
					f2,
					f1
				)
			)
		};

		REQUIRE(
			result.has_success()
		);

		CHECK(
			result.get_success_unsafe()
			==
			42
		);
	}

	SECTION(
		"test failure"
	)
	{
		result_type const result{
			fcppt::either::first_success(
				fcppt::container::array::make(
					f2,
					f3
				)
			)
		};

		REQUIRE(
			result.has_failure()
		);

		CHECK(
			result.get_failure_unsafe()
			==
			std::vector<
				std::string
			>{
				std::string{
					"f1"
				},
				std::string{
					"f2"
				}
			}
		);
	}
}
