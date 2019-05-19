//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/container/bitfield/comparison.hpp>
#include <fcppt/container/bitfield/enum_object.hpp>
#include <fcppt/container/bitfield/operators.hpp>
#include <fcppt/container/bitfield/output.hpp>
#include <fcppt/enum/names_array.hpp>
#include <fcppt/enum/names_impl_fwd.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	test1,
	test2,
	test3,
	fcppt_maximum = test3
};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wglobal-constructors)
FCPPT_PP_DISABLE_CLANG_WARNING(-Wexit-time-destructors)

fcppt::enum_::names_array<
	test_enum
> const names{{{
	FCPPT_TEXT("test1"),
	FCPPT_TEXT("test2"),
	FCPPT_TEXT("test3")
}}};

FCPPT_PP_POP_WARNING

}

namespace fcppt
{
namespace enum_
{

template<>
struct names_impl<
	test_enum
>
{
	static
	fcppt::enum_::names_array<
		test_enum
	> const &
	get()
	{
		return
			::names;
	}
};

}
}

TEST_CASE(
	"container::bitfield operators",
	"[container],[bitfield]"
)
{
	typedef
	fcppt::container::bitfield::enum_object<
		test_enum
	>
	bitfield;

	bitfield field1{
		bitfield::null()
	};

	field1[
		test_enum::test1
	] = true;

	bitfield field2(
		bitfield::null()
	);

	CHECK(
		(field2 | test_enum::test2)[
			test_enum::test2
		]
	);

	field2[
		test_enum::test3
	] = true;

	CHECK(
		(field1 | field2)
		==
		bitfield{
			test_enum::test1,
			test_enum::test3
		}
	);

	CHECK(
		(field1 & field2)
		==
		bitfield::null()
	);

	CHECK(
		(field1 ^ field2)
		==
		bitfield{
			test_enum::test1,
			test_enum::test3
		}
	);
}
