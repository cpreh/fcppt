/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


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
