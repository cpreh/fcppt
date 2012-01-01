//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/random/range_decl.hpp>

template<
	typename T
>
fcppt::random::range<T>::range(
	T const &_first,
	T const &_last
)
:
	first_(_first),
	last_(_last)
{}

template<
	typename T
>
T
fcppt::random::range<T>::first() const
{
	return first_;
}

template<
	typename T
>
T
fcppt::random::range<T>::last() const
{
	return last_;
}

#endif
