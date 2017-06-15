//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_DECORATED_VALUE_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_DECORATED_VALUE_HPP_INCLUDED

#include <fcppt/type_iso/decorate.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

/**
\brief Calculates the decorated value

\see fcppt::type_iso::decorate
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
		fcppt::type_iso::decorate<
			Result
		>(
			_value
		);
}

}
}
}

#endif
