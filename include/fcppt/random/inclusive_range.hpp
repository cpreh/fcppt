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


#ifndef SGE_RANDOM_INCLUSIVE_RANGE_HPP_INCLUDED
#define SGE_RANDOM_INCLUSIVE_RANGE_HPP_INCLUDED

#include <sge/random/range.hpp>

namespace sge
{
namespace random
{

template<
	typename T
>
class inclusive_range : public range<T> {
public:
	inclusive_range(
		T const &first_,
		T const &last_)
	:
		range<T>(
			first_,
			last_
		)
	{}
};

template<
	typename T
>
inclusive_range<T> const
make_inclusive_range(
	T const &first,
	T const &last)
{
	return inclusive_range<T>(
		first,
		last
	);
}

}
}

#endif
