#ifndef FCPPT_MATH_BOX_CENTER_HPP_INCLUDED
#define FCPPT_MATH_BOX_CENTER_HPP_INCLUDED

#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/arithmetic.hpp>

namespace fcppt
{
namespace math
{
namespace box
{
/// Returns the center of the box
template<typename T,size_type N>
typename basic<T,N>::vector const
center(
	basic<T,N> const &b)
{
	return 
		b.pos() + 
		fcppt::math::dim::structure_cast<typename basic<T,N>::vector>(
			b.dimension())/
		static_cast<T>(2);
}
}
}
}

#endif
