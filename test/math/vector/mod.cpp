//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/mod.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_vector_mod
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	uivector2;

	BOOST_CHECK_EQUAL(
		fcppt::math::vector::mod(
			uivector2{
				4u,
				3u
			},
			2u
		),
		fcppt::optional::make(
			uivector2{
				0u,
				1u
			}
		)
	);

	BOOST_CHECK(
		!fcppt::math::vector::mod(
			uivector2{
				4u,
				3u
			},
			0u
		).has_value()
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::vector::mod(
			uivector2{
				5u,
				3u
			},
			uivector2{
				3u,
				2u
			}
		),
		fcppt::optional::make(
			uivector2{
				2u,
				1u
			}
		)
	);

	BOOST_CHECK(
		!fcppt::math::vector::mod(
			uivector2{
				4u,
				3u
			},
			uivector2{
				0u,
				1u
			}
		).has_value()
	);
}
