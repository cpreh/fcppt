//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_INT_FWD_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_INT_FWD_HPP_INCLUDED

#include <fcppt/random/distribution/parameters/uniform_int_wrapper_fwd.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{
namespace parameters
{

template<
	typename IntType,
	typename Distribution
		= fcppt::random::distribution::parameters::uniform_int_wrapper
>
class uniform_int;

}
}
}
}

#endif
