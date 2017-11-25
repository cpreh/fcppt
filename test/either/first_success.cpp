//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/function_impl.hpp>
#include <fcppt/container/make_array.hpp>
#include <fcppt/either/first_success.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	either_first_success
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

	result_type const result_s{
		fcppt::either::first_success(
			fcppt::container::make_array(
				f2,
				f1
			)
		)
	};

	BOOST_REQUIRE(
		result_s.has_success()
	);

	BOOST_CHECK_EQUAL(
		result_s.get_success_unsafe(),
		42
	);

	result_type const result_f{
		fcppt::either::first_success(
			fcppt::container::make_array(
				f2,
				f3
			)
		)
	};

	BOOST_REQUIRE(
		result_f.has_failure()
	);

	BOOST_REQUIRE_EQUAL(
		result_f.get_failure_unsafe().size(),
		2u
	);

	BOOST_CHECK_EQUAL(
		result_f.get_failure_unsafe()[0],
		"f1"
	);

	BOOST_CHECK_EQUAL(
		result_f.get_failure_unsafe()[1],
		"f2"
	);
}
