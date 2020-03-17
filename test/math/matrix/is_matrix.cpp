//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/is_matrix.hpp>
#include <fcppt/math/matrix/static.hpp>


int
main()
{
	using
	large_matrix_type
	=
	fcppt::math::matrix::static_<
		double,
		3,
		3
	>;

	static_assert(
		fcppt::math::matrix::is_matrix<
			large_matrix_type
		>::value
	);

	static_assert(
		!fcppt::math::matrix::is_matrix<
			int
		>::value
	);
}
