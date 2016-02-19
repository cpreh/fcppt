//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/has_dim.hpp>
#include <fcppt/math/matrix/static.hpp>


int
main()
{
	typedef
	fcppt::math::matrix::static_<
		float,
		1,
		1
	>
	f1x1;

	static_assert(
		fcppt::math::matrix::has_dim<
			f1x1,
			1,
			1
		>::value,
		""
	);

	typedef
	fcppt::math::matrix::static_<
		float,
		2,
		3
	>
	f2x3;

	static_assert(
		fcppt::math::matrix::has_dim<
			f2x3,
			2,
			3
		>::value,
		""
	);
}
