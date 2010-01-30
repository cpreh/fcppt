//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_NEGATIVE_HPP_INCLUDED
#define FCPPT_MATH_NEGATIVE_HPP_INCLUDED

#include <fcppt/math/null.hpp>

namespace fcppt
{
namespace math
{
template<typename T>
bool negative(T const &t)
{
	return t < null<T>();
}
}
}

#endif
