//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MINMAX_PAIR_IMPL_HPP_INCLUDED
#define FCPPT_MINMAX_PAIR_IMPL_HPP_INCLUDED

#include <fcppt/minmax_pair_decl.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/format.hpp>
#include <fcppt/text.hpp>

template<
	typename T
>
fcppt::minmax_pair<T>::minmax_pair(
	T const &min_,
	T const &max_)
:
	min_(min_),
	max_(max_)
{
	check();
}

template<
	typename T
>
T fcppt::minmax_pair<T>::min() const
{
	return min_;
}

template<
	typename T
>
T fcppt::minmax_pair<T>::max() const
{
	return max_;
}

template<
	typename T
>
void fcppt::minmax_pair<T>::min(
	T const &nmin)
{
	min_ = nmin;
	check();
}

template<
	typename T
>
void fcppt::minmax_pair<T>::max(
	T const &nmax)
{
	max_ = nmax;
	check();
}

template<
	typename T
>
void fcppt::minmax_pair<T>::check()
{
	if(min() > max())
		throw exception(
			(format(
				FCPPT_TEXT("minmax_pair out of range: %1% > %2%"))
			% min()
			% max())
				.str());
}

#endif
