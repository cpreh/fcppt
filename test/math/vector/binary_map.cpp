//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/vector/binary_map.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	vector_binary_map
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	ui2_vector;

	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	i2_vector;


	auto const result(
		fcppt::math::vector::binary_map(
			ui2_vector{
				10u,
				20u
			},
			i2_vector{
				3,
				5
			},
			[](
				unsigned const _val1,
				int const _val2
			)
			{
				return
					fcppt::cast::to_signed(
						_val1
					)
					+
					_val2;
			}
		)
	);

	BOOST_CHECK_EQUAL(
		result.x(),
		13
	);

	BOOST_CHECK_EQUAL(
		result.y(),
		25
	);
}
