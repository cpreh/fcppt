//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_BOX_OUTPUT_HPP_INCLUDED

#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/size_type.hpp>
#include <ostream>

namespace fcppt
{
namespace math
{
namespace box
{

/// Outputs a box to a basic_ostream
template<
	typename T,
	size_type N,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<Ch, Traits> &stream_,
	basic<T, N> const &box_
)
{
	return stream_
		<< stream_.widen('(')
		<< box_.pos()
		<< stream_.widen(',')
		<< box_.dimension()
		<< stream_.widen(')');
}

}
}
}

#endif
