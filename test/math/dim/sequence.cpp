//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/sequence.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::dimx::sequence",
	"[math],[dim]"
)
{
	typedef
	fcppt::math::dim::static_<
		unsigned,
		2
	>
	ui2_dim;

	typedef
	fcppt::math::dim::static_<
		fcppt::optional::object<
			unsigned
		>,
		2
	>
	ui2_dim_opt;

	CHECK(
		fcppt::math::dim::sequence(
			ui2_dim_opt{
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
			ui2_dim{
				10u,
				20u
			}
		)
	);

	CHECK(
		fcppt::math::dim::sequence(
			ui2_dim_opt{
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
			ui2_dim
		>{}
	);

}
