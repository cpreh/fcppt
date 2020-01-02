//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SPHERE_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_OUTPUT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/sphere/object_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace sphere
{

/**
\brief Outputs a sphere to a stream

\ingroup fcpptmathsphere
*/
template<
	typename T,
	fcppt::math::size_type Size,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<< (
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::math::sphere::object<
		T,
		Size
	> const &_sphere
)
{
	return
		_stream
			<<
			_stream.widen('(')
			<<
			_sphere.origin()
			<<
			_stream.widen(')')
			<<
			_sphere.radius()
			<<
			_stream.widen(')');
}

}
}
}

#endif
