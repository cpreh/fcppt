//[vectorarithmetic

#include <fcppt/math/vector/vector.hpp>
#include <fcppt/math/vector/static.hpp>
#include <iostream>
#include <ostream>

int main()
{
	typedef fcppt::math::vector::static_<
		float,
		3
	>::type float3_vec;

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

	vec2 += vec1;

	std::cout << vec2 << '\n';
}
