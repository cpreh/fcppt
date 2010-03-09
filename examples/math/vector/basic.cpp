//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/vector.hpp> // includes almost everything related to vector
#include <fcppt/math/vector/dynamic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <iostream>
#include <ostream>

int main()
{
	// typedef a vector that has a static size of three elements of float
	typedef fcppt::math::vector::static_<
		float,
		3
	>::type float3_vec;

	// vectors can be constructed directly
	float3_vec obj(
		1.f,
		2.f,
		3.f
	);

	std::cout << obj << '\n'; // prints (1, 2, 3)

	// typedef a dynamically sized vector of floats
	typedef fcppt::math::vector::dynamic<
		float
	>::type float_vec;

	float_vec obj2(
		1.f,
		2.f,
		3.f
	);

	std::cout
		<< "size is: "
		<< obj2.size()
		<< " and the vector is: "
		<< obj2
		<< '\n';
}
//]
