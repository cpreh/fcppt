#include <fcppt/math/compare.hpp>
#include <fcppt/math/is_power_of_2.hpp>
#include <iostream>
#include <ostream>
#include <iosfwd>

int main()
{
{
//[mathcompare
	float const f = 0.0f;

	float const g = 0.0f;

	// should print true
	std::cout
		<< std::boolalpha
		<< fcppt::math::compare(f, g)
		<< '\n';
//]
}
{
//[mathpowerof2
	unsigned const i = 1024;

	std::cout
		<< std::boolalpha
		<< fcppt::math::is_power_of_2(i)
		<< '\n';

//]
}
}
