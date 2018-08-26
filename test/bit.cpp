//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/bit/mask.hpp>
#include <fcppt/bit/mask_c.hpp>
#include <fcppt/bit/shifted_mask.hpp>
#include <fcppt/bit/shifted_mask_c.hpp>
#include <fcppt/bit/test.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

static_assert(
	fcppt::bit::shifted_mask_c<
		unsigned,
		10
	>().get()
	==
	1u
	<< 10,
	""
);

}

TEST_CASE(
	"bit",
	"[bit]"
)
{
	CHECK(
		fcppt::bit::shifted_mask<
			unsigned
		>(
			10
		).get()
		==
		1u
		<<
		10
	);

	auto const mask_c(
		fcppt::bit::mask_c<
			unsigned,
			0xFFu
		>()
	);

	CHECK(
		mask_c.get()
		==
		0xFFu
	);

	CHECK_FALSE(
		fcppt::bit::test(
			0xF0u,
			fcppt::bit::mask<
				unsigned
			>(
				0x0FU
			)
		)
	);

	CHECK(
		fcppt::bit::test(
			0xF0u,
			fcppt::bit::mask<
				unsigned
			>(
				0x1FU
			)
		)
	);
}
