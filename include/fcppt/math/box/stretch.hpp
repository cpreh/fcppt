//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_STRETCH_HPP_INCLUDED
#define FCPPT_MATH_BOX_STRETCH_HPP_INCLUDED

#include <fcppt/math/dim/arithmetic.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/box/center.hpp>

namespace fcppt
{
namespace math
{
namespace box
{
template<typename T,size_type N>
basic<T,N> const 
stretch(
	basic<T,N> const &b,
	T const factor)
{
	typename basic<T,N>::dim const d = 
		b.size() * factor;
	return 
		basic<T,N>(
			center(
				b) - 
			fcppt::math::dim::structure_cast<typename basic<T,N>::vector>(
				d)/
			static_cast<T>(
				2),
			d);
}
}
}
}

#endif
