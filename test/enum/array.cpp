//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/array_output.hpp>
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

enum class my_enum
{
	val1,
	val2,
	val3,
	fcppt_maximum = val3
};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wglobal-constructors)
FCPPT_PP_DISABLE_CLANG_WARNING(-Wexit-time-destructors)

// NOLINTNEXTLINE(fuchsia-statically-constructed-objects)
fcppt::enum_::names_array<
	my_enum
> const names{{{ // NOLINT(cert-err58-cpp)
	FCPPT_TEXT("val1"),
	FCPPT_TEXT("val2"),
	FCPPT_TEXT("val3")
}}};

FCPPT_PP_POP_WARNING

}

namespace fcppt::enum_
{

template<>
struct names_impl<
	my_enum
>
{
	static
	fcppt::enum_::names_array<
		my_enum
	> const &
	get()
	{
		return
			::names;
	}
};

}

TEST_CASE(
	"enum::array"
	"[enum]"
)
{
	using
	int_array
	=
	fcppt::enum_::array<
		my_enum,
		int
	>;

	int_array const test1{{{
		1,
		2,
		3
	}}};

	CHECK(
		test1[
			my_enum::val1
		]
		==
		1
	);

	int_array const test2{{{
		1,
		2,
		3
	}}};

	CHECK(
		test1
		==
		test2
	);

	int_array const test3{{{
		1,
		2,
		4
	}}};

	CHECK(
		test1
		!=
		test3
	);
}
