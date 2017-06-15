//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_WRAPPER_UNIFORM_CONTAINER_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_WRAPPER_UNIFORM_CONTAINER_IMPL_HPP_INCLUDED

#include <fcppt/random/distribution/make_basic.hpp>
#include <fcppt/random/wrapper/uniform_container_decl.hpp>


template<
	typename Container,
	typename IntDistribution
>
fcppt::random::wrapper::uniform_container<
	Container,
	IntDistribution
>::uniform_container(
	Container &_container,
	param_type const &_parameters
)
:
	container_(
		_container
	),
	distribution_(
		fcppt::random::distribution::make_basic(
			_parameters
		)
	)
{
}

template<
	typename Container,
	typename IntDistribution
>
template<
	typename Generator
>
typename
fcppt::random::wrapper::uniform_container<
	Container,
	IntDistribution
>::result_type
fcppt::random::wrapper::uniform_container<
	Container,
	IntDistribution
>::operator()(
	Generator &_generator
)
{
	return
		container_.get()[
			distribution_(
				_generator
			)
		];
}

#endif
