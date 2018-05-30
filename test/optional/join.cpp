//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/join.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::join",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	typedef
	fcppt::optional::object<
		optional_string
	>
	optional_optional_string;

	CHECK(
		fcppt::optional::join(
			optional_optional_string(
				optional_string(
					"test2"
				)
			)
		)
		==
		optional_string(
			"test2"
		)
	);

	CHECK(
		fcppt::optional::join(
			optional_optional_string()
		)
		==
		optional_string()
	);
}

TEST_CASE(
	"optional::join move",
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

	CHECK(
		fcppt::optional::join(
			fcppt::optional::make(
				optional_int_movable{
					int_movable{
						42
					}
				}
			)
		)
		==
		optional_int_movable{
			int_movable{
				42
			}
		}
	);
}
