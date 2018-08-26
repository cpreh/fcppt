//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_INT_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_INT_IMPL_HPP_INCLUDED

#include <fcppt/random/distribution/base_value.hpp>
#include <fcppt/random/distribution/decorated_value.hpp>
#include <fcppt/random/distribution/parameters/uniform_int_decl.hpp>


template<
	typename IntType,
	typename Distribution
>
fcppt::random::distribution::parameters::uniform_int<
	IntType,
	Distribution
>::uniform_int(
	min const _min,
	max const _max
)
:
	min_(
		_min
	),
	max_(
		_max
	)
{
}

template<
	typename IntType,
	typename Distribution
>
typename
fcppt::random::distribution::parameters::uniform_int<
	IntType,
	Distribution
>::wrapped_param_type
fcppt::random::distribution::parameters::uniform_int<
	IntType,
	Distribution
>::convert_from() const
{
	return
		wrapped_param_type(
			fcppt::random::distribution::base_value(
				min_.get()
			),
			fcppt::random::distribution::base_value(
				max_.get()
			)
		);
}

template<
	typename IntType,
	typename Distribution
>
fcppt::random::distribution::parameters::uniform_int<
	IntType,
	Distribution
>
fcppt::random::distribution::parameters::uniform_int<
	IntType,
	Distribution
>::convert_to(
	distribution const &_dist
)
{
	return
		uniform_int(
			min(
				fcppt::random::distribution::decorated_value(
					_dist.a()
				)
			),
			max(
				fcppt::random::distribution::decorated_value(
					_dist.b()
				)
			)
		);
}

#endif
