//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_INT_WRAPPER_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_INT_WRAPPER_HPP_INCLUDED

#include <fcppt/random/distribution/parameters/uniform_int_wrapper_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <random>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{
namespace parameters
{

struct uniform_int_wrapper
{
	template<
		typename Type
	>
	struct apply
	{
		typedef
		std::uniform_int_distribution<
			Type
		>
		type;
	};
};

}
}
}
}

#endif
