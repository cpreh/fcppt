//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"strong_typedef move",
	"[strongtypedef]"
)
{
	using
	int_unique_ptr
	=
	fcppt::unique_ptr<
		int
	>;

	FCPPT_MAKE_STRONG_TYPEDEF(
		int_unique_ptr,
		strong_int_ptr
	);

	strong_int_ptr val(
		fcppt::make_unique_ptr<
			int
		>(
			1
		)
	);

	strong_int_ptr val2(
		std::move(
			val
		)
	);

	CHECK(
		*val2.get()
		==
		1
	);

	strong_int_ptr val3(
		fcppt::make_unique_ptr<
			int
		>(
			2
		)
	);

	val3 =
		std::move(
			val2
		);

	CHECK(
		*val3.get()
		==
		1
	);
}
