//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/bit/mask.hpp>
#include <fcppt/bit/mask_c.hpp>
#include <fcppt/bit/shifted_mask.hpp>
#include <fcppt/bit/shifted_mask_c.hpp>
#include <fcppt/bit/test.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	bit
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK_EQUAL(
		fcppt::bit::shifted_mask<
			unsigned
		>(
			10
		).get(),
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

	BOOST_CHECK_EQUAL(
		mask_c.get(),
		0xFFu
	);

	BOOST_CHECK(
		!fcppt::bit::test(
			0xF0u,
			fcppt::bit::mask<
				unsigned
			>(
				0x0FU
			)
		)
	);

	BOOST_CHECK(
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
