//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MINMAX_PAIR_IMPL_HPP_INCLUDED
#define FCPPT_MINMAX_PAIR_IMPL_HPP_INCLUDED

#include <fcppt/format.hpp>
#include <fcppt/homogenous_pair_impl.hpp>
#include <fcppt/invalid_minmax_pair.hpp>
#include <fcppt/minmax_pair_decl.hpp>
#include <fcppt/text.hpp>


template<
	typename T
>
fcppt::minmax_pair<T>::minmax_pair(
	T const &min_,
	T const &max_
)
:
	impl_(
		min_,
		max_
	)
{
	check();
}

template<
	typename T
>
T
fcppt::minmax_pair<T>::min() const
{
	return impl_.first;
}

template<
	typename T
>
T
fcppt::minmax_pair<T>::max() const
{
	return impl_.second;
}

template<
	typename T
>
typename fcppt::minmax_pair<T>::pair_type const
fcppt::minmax_pair<T>::pair() const
{
	return impl_;
}

template<
	typename T
>
void
fcppt::minmax_pair<T>::min(
	T const &nmin
)
{
	impl_.first = nmin;

	check();
}

template<
	typename T
>
void
fcppt::minmax_pair<T>::max(
	T const &nmax
)
{
	impl_.second = nmax;

	check();
}

template<
	typename T
>
void
fcppt::minmax_pair<T>::pair(
	pair_type const &pair_
)
{
	impl_ = pair_;
}

template<
	typename T
>
void
fcppt::minmax_pair<T>::swap(
	minmax_pair &other_
)
{
	impl_.swap(
		other_.impl_
	);
}

template<
	typename T
>
void
fcppt::minmax_pair<T>::check()
{
	if(min() > max())
		throw invalid_minmax_pair(
			(
				format(
					FCPPT_TEXT("minmax_pair out of range: %1% > %2%")
				)
				% min()
				% max()
			).str()
		);
}

template
<
	typename T
>
void
fcppt::swap(
	minmax_pair<T> &a_,
	minmax_pair<T> &b_
)
{
	a_.swap(
		b_
	);
}

#endif
