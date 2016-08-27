//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_WRAPPER_MAKE_UNIFORM_CONTAINER_ADVANCED_HPP_INCLUDED
#define FCPPT_RANDOM_WRAPPER_MAKE_UNIFORM_CONTAINER_ADVANCED_HPP_INCLUDED

#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/random/distribution/parameters/make_uniform_indices_advanced.hpp>
#include <fcppt/random/wrapper/uniform_container_impl.hpp>


namespace fcppt
{
namespace random
{
namespace wrapper
{

template<
	typename IntDistribution,
	typename Container
>
inline
fcppt::optional::object<
	fcppt::random::wrapper::uniform_container<
		Container,
		IntDistribution
	>
>
make_uniform_container_advanced(
	Container &_container
)
{
	typedef
	fcppt::random::wrapper::uniform_container<
		Container,
		IntDistribution
	>
	result_type_inner;

	return
		fcppt::optional::map(
			fcppt::random::distribution::parameters::make_uniform_indices_advanced<
				IntDistribution
			>(
				_container
			),
			[
				&_container
			](
				typename
				result_type_inner::param_type const &_parameters
			)
			{
				return
					result_type_inner(
						_container,
						_parameters
					);
			}
		);
}

}
}
}

#endif
