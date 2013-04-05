//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_NORMAL_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_NORMAL_IMPL_HPP_INCLUDED

#include <fcppt/random/distribution/base_value.hpp>
#include <fcppt/random/distribution/decorated_value.hpp>
#include <fcppt/random/distribution/parameters/normal_decl.hpp>


template<
	typename FloatType
>
fcppt::random::distribution::parameters::normal<
	FloatType
>::normal(
	mean const _mean,
	stddev const _stddev
)
:
	mean_(
		_mean
	),
	stddev_(
		_stddev
	)
{
}

template<
	typename FloatType
>
typename
fcppt::random::distribution::parameters::normal<
	FloatType
>::wrapped_param_type const
fcppt::random::distribution::parameters::normal<
	FloatType
>::convert_from() const
{
	return
		wrapped_param_type(
			fcppt::random::distribution::base_value(
				mean_.get()
			),
			fcppt::random::distribution::base_value(
				stddev_.get()
			)
		);
}

template<
	typename FloatType
>
fcppt::random::distribution::parameters::normal<
	FloatType
> const
fcppt::random::distribution::parameters::normal<
	FloatType
>::convert_to(
	distribution const &_dist
)
{
	return
		normal(
			mean(
				fcppt::random::distribution::decorated_value(
					_dist.mean()
				)
			),
			stddev(
				fcppt::random::distribution::decorated_value(
					_dist.stddev()
				)
			)
		);
}

#endif
