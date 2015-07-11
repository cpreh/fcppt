//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_BASE_VALUE_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_BASE_VALUE_HPP_INCLUDED

#include <fcppt/random/distribution/base_type.hpp>
#include <fcppt/type_iso/to_base.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

/**
\brief Calculates the base value

Calculates the base value of \a _value by calling
<code>fcppt::random::distribution::transform<Type>::base_value</code>
recursively, until no specialization is found.

\tparam Type Can be any type

\param _value The value to convert
*/
template<
	typename Type
>
inline
fcppt::random::distribution::base_type<
	Type
>
base_value(
	Type const &_value
)
{
	return
		fcppt::type_iso::to_base(
			_value
		);
}

}
}
}

#endif
