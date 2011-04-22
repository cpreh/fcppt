//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_UNIT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_UNIT_HPP_INCLUDED

namespace fcppt
{
namespace math
{
namespace vector
{

/// Creates a vector of type \tparam Vec with all components set to 0 expect for component \param _axis which is set to 1
template<
	typename Vec
>
Vec const
unit(
	typename Vec::size_type const _axis
)
{
	Vec ret;

	for(
		typename Vec::size_type index = 0;
		index < Vec::dim_wrapper::value;
		++index
	)
		ret[
			index
		] =
			static_cast<
				typename Vec::value_type
			>(
				index == _axis
				?
					1
				:
					0
			);
	return ret;
}

}
}
}

#endif
