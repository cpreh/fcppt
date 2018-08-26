//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/container/at_optional.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::at_optional",
	"[container]"
)
{
	std::vector<
		int
	> const int_vector{
		1,
		2
	};

	typedef
	fcppt::optional::reference<
		int const
	>
	optional_int_ref;

	CHECK(
		fcppt::container::at_optional(
			int_vector,
			1
		)
		==
		optional_int_ref{
			fcppt::make_cref(
				int_vector[
					1
				]
			)
		}
	);

	CHECK(
		fcppt::container::at_optional(
			int_vector,
			2
		)
		==
		optional_int_ref{}
	);
}
