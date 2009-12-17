#ifndef FCPPT_MATH_MACHINE_EPSILON_HPP_INCLUDED
#define FCPPT_MATH_MACHINE_EPSILON_HPP_INCLUDED

#include <limits>

namespace fcppt
{
namespace math
{
template<typename T>
struct machine_epsilon
{
	static T
	value()
	{
		return std::numeric_limits<T>::epsilon();
	}
};
}
}

#endif
