//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/sequence.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::sequence",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	ui2_vector;

	typedef
	fcppt::math::vector::static_<
		fcppt::optional::object<
			unsigned
		>,
		2
	>
	ui2_vector_opt;

	CHECK(
		fcppt::math::vector::sequence(
			ui2_vector_opt{
				fcppt::optional::make(
					10u
				),
				fcppt::optional::make(
					20u
				)
			}
		)
		==
		fcppt::optional::make(
			ui2_vector{
				10u,
				20u
			}
		)
	);

	CHECK(
		fcppt::math::vector::sequence(
			ui2_vector_opt{
				fcppt::optional::object<
					unsigned
				>{},
				fcppt::optional::make(
					20u
				)
			}
		)
		==
		fcppt::optional::object<
			ui2_vector
		>{}
	);
}
