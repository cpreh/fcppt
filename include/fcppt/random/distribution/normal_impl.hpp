//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_NORMAL_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_NORMAL_IMPL_HPP_INCLUDED

#include <fcppt/random/distribution/define_call.hpp>
#include <fcppt/random/distribution/normal_decl.hpp>


template<
	typename FloatType
>
fcppt::random::distribution::normal<
	FloatType
>::normal(
	mean const _mean,
	sigma const _sigma
)
:
	wrapped_(
		_mean.get(),
		_sigma.get()
	)
{
}

FCPPT_RANDOM_DISTRIBUTION_DEFINE_CALL(
	template<
		typename FloatType
	>,
	fcppt::random::distribution::normal<
		FloatType
	>
)

#endif
