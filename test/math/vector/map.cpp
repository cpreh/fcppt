//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/vector/map.hpp>
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
	vector_map
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	ui2_vector;

	ui2_vector const vector{
		10u,
		20u
	};

	auto const result(
		fcppt::math::vector::map(
			vector,
			[](
				unsigned const _val
			)
			{
				return
					fcppt::cast::to_signed(
						_val
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		result.x(),
		10
	);

	BOOST_CHECK_EQUAL(
		result.y(),
		20
	);
}
