//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/catch/optional.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::sequence",
	"[optional]"
)
{
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

	CHECK(
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
		==
		fcppt::optional::make(
			int_vector{
				10,
				20
			}
		)
	);

	CHECK(
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
		==
		result_type{}
	);
}

TEST_CASE(
	"optional::sequence move",
	"[optional]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	int_movable;

	typedef
	fcppt::optional::object<
		int_movable
	>
	optional_int_movable;

	typedef
	std::vector<
		optional_int_movable
	>
	optional_int_movable_vector;

	typedef
	std::vector<
		int_movable
	>
	int_movable_vector;

	typedef
	fcppt::optional::object<
		int_movable_vector
	>
	result_type;

	CHECK(
		fcppt::optional::sequence<
			int_movable_vector
		>(
			fcppt::container::make<
				optional_int_movable_vector
			>(
				optional_int_movable{
					int_movable{
						42
					}
				}
			)
		)
		==
		result_type{
			fcppt::container::make<
				int_movable_vector
			>(
				int_movable{
					42
				}
			)
		}
	);
}
