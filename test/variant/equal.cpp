//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/type_info.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"variant equal",
	"[variant]"
)
{
	typedef
	fcppt::variant::variadic<
		bool,
		int,
		std::string
	>
	variant;

	std::string const string(
		"hello world"
	);

	variant const v1(
		string
	);

	variant const v2(
		string
	);

	CHECK(
		v1 == v2
	);

	variant const v3(
		42
	);

	CHECK(
		v1 != v3
	);

	CHECK(
		fcppt::variant::type_info(
			v1
		)
		==
		fcppt::variant::type_info(
			v2
		)
	);
}
