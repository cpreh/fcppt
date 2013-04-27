//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_UNIT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_UNIT_HPP_INCLUDED

#include <fcppt/no_init.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Returns the n-th basis vector of the canonical basis.
\ingroup fcpptmathvector
\tparam Vec The destination vector type.
\param _axis The basis axis

Creates a vector of type \p Vec with all components set to 0 expect for component \p _axis which is set to 1:

\f[
e_i = (0,\ldots,0,1,0,\ldots,0)
\f]
*/
template<
	typename Vec
>
Vec const
unit(
	typename Vec::size_type const _axis
)
{
	Vec ret{
		fcppt::no_init()
	};

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
