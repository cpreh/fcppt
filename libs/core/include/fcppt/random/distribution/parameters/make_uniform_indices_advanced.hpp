//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_INDICES_ADVANCED_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_INDICES_ADVANCED_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
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
	typename Distribution,
	typename Container
>
fcppt::optional::object<
	fcppt::random::distribution::parameters::uniform_int<
		typename
		Container::size_type,
		Distribution
	>
>
make_uniform_indices_advanced(
	Container const &_container
)
{
	typedef
	fcppt::random::distribution::parameters::uniform_int<
		typename
		Container::size_type,
		Distribution
	>
	param_type;

	typedef
	fcppt::optional::object<
		param_type
	>
	result_type;

	return
		_container.empty()
		?
			result_type()
		:
			result_type(
				param_type(
					typename param_type::min(
						0u
					),
					typename param_type::max(
						_container.size() - 1u
					)
				)
			)
		;
}

}
}
}
}

#endif
