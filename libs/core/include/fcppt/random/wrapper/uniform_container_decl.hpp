//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_WRAPPER_UNIFORM_CONTAINER_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_WRAPPER_UNIFORM_CONTAINER_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/wrapper/uniform_container_fwd.hpp>


namespace fcppt
{
namespace random
{
namespace wrapper
{

template<
	typename Container,
	typename IntDistribution
>
class uniform_container
{
public:
	typedef
	fcppt::container::to_reference_type<
		Container
	>
	result_type;

	typedef
	fcppt::random::distribution::parameters::uniform_int<
		typename
		Container::size_type,
		IntDistribution
	>
	param_type;

	uniform_container(
		Container &,
		param_type const &
	);

	template<
		typename Generator
	>
	result_type
	operator()(
		Generator &
	);
private:
	fcppt::reference<
		Container
	>
	container_;

	fcppt::random::distribution::basic<
		param_type
	>
	distribution_;
};

}
}
}

#endif
