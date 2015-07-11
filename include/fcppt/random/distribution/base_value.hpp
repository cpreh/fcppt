//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_BASE_VALUE_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_BASE_VALUE_HPP_INCLUDED

#include <fcppt/random/distribution/base_type.hpp>
#include <fcppt/type_iso/undecorate.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

/**
\brief Calculates the base value

\see fcppt::type_iso::undecorate
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
		fcppt::type_iso::undecorate(
			_value
		);
}

}
}
}

#endif
