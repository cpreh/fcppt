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


#ifndef SGE_DETAIL_STRONG_TYPEDEF_CAST_HPP_INCLUDED
#define SGE_DETAIL_STRONG_TYPEDEF_CAST_HPP_INCLUDED

#include <sge/sn_cast.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <boost/utility/enable_if.hpp>

namespace sge
{
namespace detail
{

template<
	typename T,
	typename U
>
typename boost::disable_if<
	boost::mpl::and_<
		boost::is_fundamental<
			T
		>,
		boost::is_fundamental<
			U
		>
	>,
	T
>::type
strong_typedef_cast(
	U const &u
)
{
	return T(u);
}

template<
	typename T,
	typename U
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_fundamental<
			T
		>,
		boost::is_fundamental<
			U
		>
	>,
	T
>::type
strong_typedef_cast(
	U const &u
)
{
	return sn_cast<
		T
	>(
		u
	);
}

}
}

#endif
