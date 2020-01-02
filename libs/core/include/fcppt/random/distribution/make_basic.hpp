//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_MAKE_BASIC_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_MAKE_BASIC_HPP_INCLUDED

#include <fcppt/random/distribution/basic_impl.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

template<
	typename Parameters
>
fcppt::random::distribution::basic<
	Parameters
>
make_basic(
	Parameters const &_parameters
)
{
	return
		fcppt::random::distribution::basic<
			Parameters
		>(
			_parameters
		);
}

}
}
}

#endif
