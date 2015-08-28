//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_INPUT_HPP_INCLUDED
#define FCPPT_MATH_DIM_INPUT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/one_dimensional_input.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Reads a dim from \p s, expecting it in the format

<pre>(a_1,a_2,...)</pre>

where <code>a_i</code> are the components

\ingroup fcpptmathdim
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S,
	typename Ch,
	typename Traits
>
inline
std::basic_istream<
	Ch,
	Traits
> &
operator >> (
	std::basic_istream<
		Ch,
		Traits
	> &_stream,
	fcppt::math::dim::object<
		T,
		N,
		S
	> &_dim
)
{
	return
		fcppt::math::detail::one_dimensional_input(
			_stream,
			_dim
		);
}

}
}
}

#endif
