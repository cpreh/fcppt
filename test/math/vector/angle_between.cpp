//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/diff.hpp>
#include <fcppt/math/pi.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/angle_between.hpp>
#include <fcppt/math/vector/angle_between_cast.hpp>
#include <fcppt/math/vector/signed_angle_between.hpp>
#include <fcppt/math/vector/signed_angle_between_cast.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
float
real;

real const epsilon{
	std::numeric_limits<
		real
	>::epsilon()
};

auto const half_pi{
	fcppt::math::pi<
		real
	>()
	/
	2.f
};

inline
bool
compare(
	real const _t1,
	real const _t2
)
{
	return
		fcppt::math::diff(
			_t1,
			_t2
		)
		<
		epsilon;
}

typedef
fcppt::math::vector::static_<
	unsigned,
	2
>
uivector2;

typedef
fcppt::math::vector::static_<
	real,
	2
>
fvector2;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	vector_angle_between
)
{
FCPPT_PP_POP_WARNING

	fvector2 const
		vec1{1.f, 0.f},
		vec2{0.f, 1.f};

	BOOST_CHECK(
		::compare(
			fcppt::math::vector::angle_between(
				vec1,
				vec2
			),
			half_pi
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	vector_angle_between_cast
)
{
FCPPT_PP_POP_WARNING

	uivector2 const
		vec1{1u, 0u},
		vec2{0u, 1u};

	BOOST_CHECK(
		::compare(
			fcppt::math::vector::angle_between_cast<
				real
			>(
				vec1,
				vec2
			),
			half_pi
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	vector_signed_angle_between
)
{
FCPPT_PP_POP_WARNING

	fvector2 const
		vec1{2.f, 1.f},
		vec2{2.f, 2.f};

	BOOST_CHECK(
		::compare(
			fcppt::math::vector::signed_angle_between(
				vec1,
				vec2
			),
			half_pi
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	vector_signed_angle_between_cast
)
{
FCPPT_PP_POP_WARNING

	uivector2 const
		vec1{2u, 1u},
		vec2{2u, 2u};

	BOOST_CHECK(
		::compare(
			fcppt::math::vector::signed_angle_between_cast<
				real
			>(
				vec1,
				vec2
			),
			half_pi
		)
	);
}
