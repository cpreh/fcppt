//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_OUTPUT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/one_dimensional_output.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Outputs a vector to a stream

\ingroup fcpptmathvector

Uses the output format <pre>(a_1,a_2,...)</pre> where <code>a_i</code> are the
vector's components.
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S,
	typename Ch,
	typename Traits
>
inline
std::basic_ostream<
	Ch,
	Traits
> &
operator<< (
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_vector
)
{
	return
		fcppt::math::detail::one_dimensional_output(
			_stream,
			_vector
		);
}

}
}
}

#endif
