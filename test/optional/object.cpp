//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


template
class
fcppt::optional::object<
	int
>;

TEST_CASE(
	"optional general",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	optional_string test{};

	CHECK_FALSE(
		test.has_value()
	);

	test =
		optional_string(
			"test"
		);

	REQUIRE(
		test.has_value()
	);

	CHECK(
		test.get_unsafe()
		==
		"test"
	);

	test =
		optional_string();

	CHECK_FALSE(
		test.has_value()
	);
}
