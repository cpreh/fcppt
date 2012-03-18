//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_IMPL_HPP_INCLUDED

#include <fcppt/random/generator/basic_pseudo_decl.hpp>


template<
	typename Wrapped
>
inline
fcppt::random::generator::basic_pseudo<
	Wrapped
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
	typename Wrapped
>
inline
fcppt::random::generator::basic_pseudo<
	Wrapped
>::~basic_pseudo()
{
}

template<
	typename Wrapped
>
inline
typename fcppt::random::generator::basic_pseudo<
	Wrapped
>::result_type
fcppt::random::generator::basic_pseudo<
	Wrapped
>::operator()()
{
	return wrapped_();
}

template<
	typename Wrapped
>
inline
typename fcppt::random::generator::basic_pseudo<
	Wrapped
>::result_type
fcppt::random::generator::basic_pseudo<
	Wrapped
>::min() const
{
	return wrapped_.min();
}

template<
	typename Wrapped
>
inline
typename fcppt::random::generator::basic_pseudo<
	Wrapped
>::result_type
fcppt::random::generator::basic_pseudo<
	Wrapped
>::max() const
{
	return wrapped_.max();
}

#endif
