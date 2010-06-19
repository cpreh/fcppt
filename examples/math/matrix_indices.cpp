//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[matrixindices
#include <fcppt/math/vector/vector.hpp>
#include <fcppt/math/vector/dot.hpp>
#include <fcppt/math/matrix/matrix.hpp>
#include <iostream>
#include <ostream>

int main()
{
	typedef fcppt::math::vector::static_<
		int,
		3
	>::type vec4;

	typedef fcppt::math::matrix::static_<
		int,
		3,
		3
	>::type matrix4x4;

	matrix4x4 m(
		1,2,3,
		5,6,7,
		8,9,10);
	
	// Will output 7 (third column, second row), _not_ 9!
	std::cout << m[2][1] << '\n';

	// Take the scalar product of the first column and the second column, will output 104
	std::cout << fcppt::math::vector::dot(m[0],m[1]) << '\n';
}

//]
