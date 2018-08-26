//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_INDICES_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_INDICES_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/random/distribution/parameters/make_uniform_indices_advanced.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
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
	typename Container
>
fcppt::optional::object<
	fcppt::random::distribution::parameters::uniform_int<
		typename
		Container::size_type,
		fcppt::random::distribution::parameters::uniform_int_wrapper
	>
>
make_uniform_indices(
	Container const &_container
)
{
	return
		fcppt::random::distribution::parameters::make_uniform_indices_advanced<
			fcppt::random::distribution::parameters::uniform_int_wrapper
		>(
			_container
		);
}

}
}
}
}

#endif
