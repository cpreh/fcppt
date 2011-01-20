//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MACHINE_EPSILON_HPP_INCLUDED
#define FCPPT_MATH_MACHINE_EPSILON_HPP_INCLUDED

#include <limits>

namespace fcppt
{
namespace math
{

/// An epsilon for floating point types
template<
	typename T
>
struct machine_epsilon
{
	/// Returns the epsilon value
	static T
	value()
	{
		return std::numeric_limits<T>::epsilon();
	}
};

}
}

#endif
