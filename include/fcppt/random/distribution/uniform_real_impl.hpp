//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_UNIFORM_REAL_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_UNIFORM_REAL_IMPL_HPP_INCLUDED

#include <fcppt/random/distribution/define_call.hpp>
#include <fcppt/random/distribution/uniform_real_decl.hpp>


template<
	typename FloatType
>
fcppt::random::distribution::uniform_real<
	FloatType
>::uniform_real(
	min const _min,
	sup const _sup
)
:
	wrapped_(
		_min.get(),
		_sup.get()
	)
{
}

FCPPT_RANDOM_DISTRIBUTION_DEFINE_CALL(
	template<
		typename FloatType
	>,
	fcppt::random::distribution::uniform_real<
		FloatType
	>
)

#endif
