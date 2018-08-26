//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_DIM_OUTPUT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/one_dimensional_output.hpp>
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
\brief Outputs a dim to \p s, in the format

<pre>(a_1,a_2,...)</pre>

where <code>a_i</code> are the dim's components.
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
std::basic_ostream<
	Ch,
	Traits
> &
operator<< (
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::math::dim::object<
		T,
		N,
		S
	> const &_dim
)
{
	return
		fcppt::math::detail::one_dimensional_output(
			_stream,
			_dim
		);
}

}
}
}

#endif
