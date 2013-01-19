//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_IMPL_HPP_INCLUDED

#include <fcppt/random/generator/basic_pseudo_decl.hpp>


template<
	typename Generator
>
inline
fcppt::random::generator::basic_pseudo<
	Generator
>::basic_pseudo(
	seed const _seed
)
:
	wrapped_(
		_seed.get()
	)
{
}

template<
	typename Generator
>
inline
fcppt::random::generator::basic_pseudo<
	Generator
>::~basic_pseudo()
{
}

template<
	typename Generator
>
inline
typename fcppt::random::generator::basic_pseudo<
	Generator
>::result_type
fcppt::random::generator::basic_pseudo<
	Generator
>::operator()()
{
	return wrapped_();
}

template<
	typename Generator
>
inline
typename fcppt::random::generator::basic_pseudo<
	Generator
>::result_type
fcppt::random::generator::basic_pseudo<
	Generator
>::min()
{
	return wrapped::min();
}

template<
	typename Generator
>
inline
typename fcppt::random::generator::basic_pseudo<
	Generator
>::result_type
fcppt::random::generator::basic_pseudo<
	Generator
>::max()
{
	return wrapped::max();
}

#endif
