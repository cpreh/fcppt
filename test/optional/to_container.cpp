//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/to_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	optional_to_container
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec1{
		fcppt::optional::to_container<
			int_vector
		>(
			optional_int{
				42
			}
		)
	};

	BOOST_REQUIRE_EQUAL(
		vec1.size(),
		1u
	);

	BOOST_CHECK_EQUAL(
		vec1[0],
		42
	);

	int_vector const vec2{
		fcppt::optional::to_container<
			int_vector
		>(
			optional_int{}
		)
	};

	BOOST_CHECK(
		vec2.empty()
	);
}

BOOST_AUTO_TEST_CASE(
	optional_to_container_move
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_vector;

	int_vector const vec1{
		fcppt::optional::to_container<
			int_vector
		>(
			optional_int{
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			}
		)
	};

	BOOST_REQUIRE_EQUAL(
		vec1.size(),
		1u
	);

	BOOST_CHECK_EQUAL(
		*vec1[0],
		42
	);

	int_vector const vec2{
		fcppt::optional::to_container<
			int_vector
		>(
			optional_int{}
		)
	};

	BOOST_CHECK(
		vec2.empty()
	);
}
