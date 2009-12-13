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


#ifndef FCPPT_MINMAX_PAIR_DECL_HPP_INCLUDED
#define FCPPT_MINMAX_PAIR_DECL_HPP_INCLUDED

#include <fcppt/minmax_pair_fwd.hpp>

namespace fcppt
{

template<
	typename T
>
class minmax_pair
{
public:
	minmax_pair(
		T const &min,
		T const &max
	);

	T min() const;

	T max() const;

	void
	min(
		T const &
	);

	void
	max(
		T const &
	);
private:
	void check();

	T
		min_,
		max_;
};

}

#endif
