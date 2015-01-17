//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_MAKE_VARIATE_HPP_INCLUDED
#define FCPPT_RANDOM_MAKE_VARIATE_HPP_INCLUDED

#include <fcppt/random/variate_impl.hpp>


namespace fcppt
{
namespace random
{

template<
	typename Generator,
	typename Distribution
>
fcppt::random::variate<
	Generator,
	Distribution
>
make_variate(
	Generator &_generator,
	Distribution const &_distribution
)
{
	return
		fcppt::random::variate<
			Generator,
			Distribution
		>(
			_generator,
			_distribution
		);
}

}
}

#endif
