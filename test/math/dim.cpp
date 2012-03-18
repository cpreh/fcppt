//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/fill.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef fcppt::math::dim::static_<
	unsigned,
	2
>::type ui2_dim;

}

BOOST_AUTO_TEST_CASE(dim_fill)
{
	ui2_dim const dim(
		fcppt::math::dim::fill<
			2
		>(
			42u
		)
	);

	BOOST_REQUIRE(
		dim.w() == 42
		&& dim.h() == 42
	);
}
