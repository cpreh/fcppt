//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/container/maybe_front.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::maybe_front",
	"[container]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	fcppt::optional::reference<
		int const
	>
	optional_int_ref;

	int_vector const empty{};

	CHECK_FALSE(
		fcppt::container::maybe_front(
			empty
		).has_value()
	);

	int_vector const vec12{
		1,
		2
	};

	CHECK(
		fcppt::container::maybe_front(
			vec12
		)
		==
		optional_int_ref(
			fcppt::make_cref(
				vec12.front()
			)
		)
	);
}
