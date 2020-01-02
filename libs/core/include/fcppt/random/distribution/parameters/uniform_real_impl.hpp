//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_REAL_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_UNIFORM_REAL_IMPL_HPP_INCLUDED

#include <fcppt/random/distribution/base_value.hpp>
#include <fcppt/random/distribution/decorated_value.hpp>
#include <fcppt/random/distribution/parameters/uniform_real_decl.hpp>


template<
	typename FloatType
>
fcppt::random::distribution::parameters::uniform_real<
	FloatType
>::uniform_real(
	min const _min,
	sup const _sup
)
:
	min_(
		_min
	),
	sup_(
		_sup
	)
{
}

template<
	typename FloatType
>
typename
fcppt::random::distribution::parameters::uniform_real<
	FloatType
>::wrapped_param_type
fcppt::random::distribution::parameters::uniform_real<
	FloatType
>::convert_from() const
{
	return
		wrapped_param_type(
			fcppt::random::distribution::base_value(
				min_.get()
			),
			fcppt::random::distribution::base_value(
				sup_.get()
			)
		);
}

template<
	typename FloatType
>
fcppt::random::distribution::parameters::uniform_real<
	FloatType
>
fcppt::random::distribution::parameters::uniform_real<
	FloatType
>::convert_to(
	distribution const &_dist
)
{
	return
		uniform_real(
			min(
				fcppt::random::distribution::decorated_value(
					_dist.a()
				)
			),
			sup(
				fcppt::random::distribution::decorated_value(
					_dist.b()
				)
			)
		);
}

#endif
