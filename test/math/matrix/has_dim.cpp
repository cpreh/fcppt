//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/math/matrix/has_dim.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

// test overloaded functions

template<
	typename Matrix
>
typename boost::enable_if<
	fcppt::math::matrix::has_dim<
		Matrix,
		1,
		1
	>,
	bool
>::type
is_1x1(
	Matrix const &
)
{
	return true;
}

template<
	typename Matrix
>
typename boost::disable_if<
	fcppt::math::matrix::has_dim<
		Matrix,
		1,
		1
	>,
	bool
>::type
is_1x1(
	Matrix const &
)
{
	return false;
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(math_matrix_has_dim)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::math::matrix::static_<
		float,
		1,
		1
	>::type f1x1;

	f1x1 const m1x1{
		fcppt::no_init()
	};

	typedef fcppt::math::matrix::static_<
		float,
		2,
		2
	>::type f2x2;

	f2x2 const m2x2{
		fcppt::no_init()
	};

	BOOST_REQUIRE(
		is_1x1(
			m1x1
		)
	);


	BOOST_REQUIRE(
		!is_1x1(
			m2x2
		)
	);
}
