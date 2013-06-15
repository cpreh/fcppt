//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[matrixtransform
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/translation.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int main()
{
	typedef fcppt::math::vector::static_<
		float,
		4
	> vec4f;

	typedef fcppt::math::matrix::static_<
		float,
		4,
		4
	> matrix4x4f;

	// initialize the vector so it is compatible for affine transformations
	vec4f const vec(
		0.f,
		0.f,
		0.f,
		1.f
	);

	// create a translation matrix

	matrix4x4f const trans(
		fcppt::math::matrix::translation(
			10.f,
			0.f,
			5.f
		)
	);

	// apply the transformation to the vector

	std::cout << (trans * vec) << '\n';
}

//]
