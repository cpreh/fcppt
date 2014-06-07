//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_VARIATE_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_VARIATE_IMPL_HPP_INCLUDED

#include <fcppt/random/variate_decl.hpp>


template<
	typename Generator,
	typename Distribution
>
fcppt::random::variate<
	Generator,
	Distribution
>::variate(
	Generator &_generator,
	Distribution const &_distribution
)
:
	generator_(
		_generator
	),
	distribution_(
		_distribution
	)
{
}

template<
	typename Generator,
	typename Distribution
>
fcppt::random::variate<
	Generator,
	Distribution
>::variate(
	Generator &_generator,
	param_type const &_param
)
:
	generator_(
		_generator
	),
	distribution_(
		_param
	)
{
}

template<
	typename Generator,
	typename Distribution
>
typename fcppt::random::variate<
	Generator,
	Distribution
>::result_type
fcppt::random::variate<
	Generator,
	Distribution
>::operator()()
{
	return
		distribution_(
			generator_.get()
		);
}

#endif
