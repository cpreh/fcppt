//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_DECORATED_VALUE_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_DECORATED_VALUE_HPP_INCLUDED

#include <fcppt/type_iso/to_decorated.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

/**
\brief Calculates the decorated value

Calculates the decorated value of type \a Result from \a _value by calling
<code>fcppt::random::distribution::transform<Result>::decorated_value</code>
recursively, until \a Result and \a Value are the same type.

\tparam Result Can be any type

\tparam Type Can be any type

\param _value The value to convert
*/
template<
	typename Result,
	typename Type
>
inline
Result
decorated_value(
	Type const &_value
)
{
	return
		fcppt::type_iso::to_decorated<
			Result
		>(
			_value
		);
}

}
}
}

#endif
