//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_UNIFORM_INT_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_UNIFORM_INT_IMPL_HPP_INCLUDED

#include <fcppt/random/distribution/define_call.hpp>
#include <fcppt/random/distribution/uniform_int_decl.hpp>


template<
	typename IntType
>
fcppt::random::distribution::uniform_int<
	IntType
>::uniform_int(
	min const _min,
	max const _max
)
:
	wrapped_(
		_min.get(),
		_max.get()
	)
{
}

FCPPT_RANDOM_DISTRIBUTION_DEFINE_CALL(
	template<
		typename IntType
	>,
	fcppt::random::distribution::uniform_int<
		IntType
	>
)

#endif
