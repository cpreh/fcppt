//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/mod.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::mod",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	uivector2;

	typedef
	fcppt::optional::object<
		uivector2
	>
	optional_uivector2;

	CHECK(
		fcppt::math::vector::mod(
			uivector2{
				4u,
				3u
			},
			2u
		)
		==
		fcppt::optional::make(
			uivector2{
				0u,
				1u
			}
		)
	);

	CHECK(
		fcppt::math::vector::mod(
			uivector2{
				4u,
				3u
			},
			0u
		)
		==
		optional_uivector2{}
	);

	CHECK(
		fcppt::math::vector::mod(
			uivector2{
				5u,
				3u
			},
			uivector2{
				3u,
				2u
			}
		)
		==
		fcppt::optional::make(
			uivector2{
				2u,
				1u
			}
		)
	);

	CHECK(
		fcppt::math::vector::mod(
			uivector2{
				4u,
				3u
			},
			uivector2{
				0u,
				1u
			}
		)
		==
		optional_uivector2{}
	);
}
