//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/optional/to_pointer.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::to_pointer",
	"[optional]"
)
{
	int const val{
		42
	};

	using
	optional_int_cref
	=
	fcppt::optional::reference<
		int const
	>;

	CHECK(
		fcppt::optional::to_pointer(
			optional_int_cref{}
		)
		==
		nullptr
	);

	CHECK(
		fcppt::optional::to_pointer(
			optional_int_cref{
				fcppt::make_cref(
					val
				)
			}
		)
		==
		&val
	);
}
