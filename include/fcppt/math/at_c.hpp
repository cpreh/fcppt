//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_AT_C_HPP_INCLUDED
#define FCPPT_MATH_AT_C_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Free function version of at_c<>

\ingroup fcpptmath
*/
template<
	fcppt::math::size_type Index,
	typename Type
>
inline
typename
Type::reference
at_c(
	Type &_value
)
{
	return
		_value . template at_c<
			Index
		>();
}

/**
\brief Free function version of at_c<>

\ingroup fcpptmath
*/
template<
	fcppt::math::size_type Index,
	typename Type
>
inline
typename
Type::const_reference
at_c(
	Type const &_value
)
{
	return
		_value . template at_c<
			Index
		>();
}

}
}

#endif
