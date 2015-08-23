//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_AT_HPP_INCLUDED
#define FCPPT_MATH_AT_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/exception.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Throw an exception if the index is out of range

\ingroup fcpptmath
*/
template<
	typename Type
>
inline
fcppt::container::to_reference_type<
	Type
>
at(
	Type &_value,
	typename Type::size_type const _index
)
{
	if(
		_index
		>=
		Type::static_size::value
	)
		throw
			fcppt::math::exception{
				FCPPT_TEXT("Index out of range")
			};

	return
		_value[
			_index
		];
}

}
}

#endif
