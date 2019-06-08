//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/optional.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/index_of_array.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	test1,
	test2,
	fcppt_maximum = test2
};

}

TEST_CASE(
	"enum::index_of_array",
	"[enum]"
)
{
	typedef
	fcppt::enum_::array<
		test_enum,
		unsigned
	>
	array;

	array const test{{{
		1u,
		2u
	}}};

	CHECK(
		fcppt::enum_::index_of_array(
			test,
			2u
		)
		==
		fcppt::optional::make(
			test_enum::test2
		)
	);

	CHECK(
		fcppt::enum_::index_of_array(
			test,
			3u
		)
		==
		fcppt::optional::object<
			test_enum
		>{}
	);
}
