//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"variant::holds_type",
	"[variant]"
)
{
	typedef
	fcppt::variant::object<
		metal::list<
			int,
			std::string
		>
	>
	variant;

	std::string const string(
		"hello world"
	);

	variant test(
		string
	);

	CHECK(
		fcppt::variant::holds_type<
			std::string
		>(
			test
		)
	);

	CHECK_FALSE(
		fcppt::variant::holds_type<
			int
		>(
			test
		)
	);

	variant const test2(
		42
	);

	CHECK_FALSE(
		fcppt::variant::holds_type<
			std::string
		>(
			test2
		)
	);

	CHECK(
		fcppt::variant::holds_type<
			int
		>(
			test2
		)
	);
}
