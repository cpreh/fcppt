//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/to_optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"variant::to_optional",
	"[variant]"
)
{
	typedef
	fcppt::variant::object<
		int,
		std::string
	>
	variant;

	variant const var(
		42
	);

	CHECK(
		fcppt::variant::to_optional<
			int
		>(
			var
		)
		==
		fcppt::optional::object<
			int
		>(
			42
		)
	);

	CHECK(
		fcppt::variant::to_optional<
			std::string
		>(
			var
		)
		==
		fcppt::optional::object<
			std::string
		>()
	);
}

TEST_CASE(
	"variant::to_optional move",
	"[variant]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	int_movable;

	CHECK(
		fcppt::variant::to_optional<
			int_movable
		>(
			fcppt::variant::object<
				int,
				int_movable
			>{
				int_movable{
					42
				}
			}
		)
		==
		fcppt::optional::make(
			int_movable{
				42
			}
		)
	);
}
