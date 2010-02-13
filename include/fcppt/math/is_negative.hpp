#ifndef FCPPT_MATH_IS_NEGATIVE_HPP_INCLUDED
#define FCPPT_MATH_IS_NEGATIVE_HPP_INCLUDED

#include <fcppt/math/null.hpp>

namespace fcppt
{
namespace math
{
template<typename T>
bool
is_negative(
	T const &_t)
{
	return 
		_t < fcppt::math::null<T>();
}
}
}

#endif
