//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[vectorarithmetic
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/vector/dot.hpp>
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
		3
	> float3_vec;

	float3_vec const vec1(
		1.f,
		2.f,
		3.f
	);

	float3_vec vec2(
		10.f,
		20.f,
		30.f
	);

	// add two vectors
	vec2 += vec1;

	std::cout << vec2 << '\n';

	// multiply by a scalar
	vec2 *= 0.5f;

	std::cout << vec2 << '\n';

	typedef fcppt::math::dim::static_<
		float,
		3
	> float3_dim;

	float3_dim const dim_(
		1.4f,
		1.5f,
		1.6f
	);

	// dims can be added to or subtracted from vectors
	std::cout << (vec2 - dim_) << '\n';

	// Computes the dot product of two vectors
	float3_vec::value_type const dotp(
		fcppt::math::vector::dot(
			vec1,
			vec2
		)
	);

	std::cout << dotp << '\n';
}
//]
