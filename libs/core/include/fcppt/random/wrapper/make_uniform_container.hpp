//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_WRAPPER_MAKE_UNIFORM_CONTAINER_HPP_INCLUDED
#define FCPPT_RANDOM_WRAPPER_MAKE_UNIFORM_CONTAINER_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/random/distribution/parameters/uniform_int_wrapper.hpp>
#include <fcppt/random/wrapper/make_uniform_container_advanced.hpp>
#include <fcppt/random/wrapper/uniform_container_impl.hpp>


namespace fcppt
{
namespace random
{
namespace wrapper
{

template<
	typename Container
>
inline
fcppt::optional::object<
	fcppt::random::wrapper::uniform_container<
		Container,
		fcppt::random::distribution::parameters::uniform_int_wrapper
	>
>
make_uniform_container(
	Container &_container
)
{
	return
		fcppt::random::wrapper::make_uniform_container_advanced<
			fcppt::random::distribution::parameters::uniform_int_wrapper,
			Container
		>(
			_container
		);
}

}
}
}

#endif
