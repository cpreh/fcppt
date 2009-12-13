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


#ifndef SGE_RANDOM_LAST_EXCLUSIVE_RANGE_HPP_INCLUDED
#define SGE_RANDOM_LAST_EXCLUSIVE_RANGE_HPP_INCLUDED

#include <sge/random/range.hpp>
#include <sge/random/exclusive_range_error.hpp>
#include <sge/text.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_integral.hpp>

namespace sge
{
namespace random
{

template<
	typename T,
	typename Enable = void
>
class last_exclusive_range;

template<
	typename T
>
class last_exclusive_range<
	T,
	typename boost::enable_if<
		boost::is_integral<
			T
		>
	>::type
>
:
	public range<
		T
	>
{
public:
	last_exclusive_range(
		T const &first,
		T const &last)
	:
		range<T>(
			first,
			last - static_cast<T>(1))
	{
		if(first == last)
			throw exclusive_range_error(
				SGE_TEXT("last_exclusive_range empty!"));
	}
};

template<
	typename T
>
last_exclusive_range<T> const
make_last_exclusive_range(
	T const &first,
	T const &last)
{
	return last_exclusive_range<T>(
		first,
		last
	);
}

}
}

#endif
