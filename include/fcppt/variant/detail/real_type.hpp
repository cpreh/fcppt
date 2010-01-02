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


#ifndef FCPPT_VARIANT_DETAIL_REAL_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_REAL_TYPE_HPP_INCLUDED

#include <fcppt/variant/recursive_fwd.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_same.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types,
	typename Element
>
struct real_type
{
#if 0
private:
	typedef recursive<
		Element
	> recursive_type;
public:
	typedef typename boost::mpl::if_<
		boost::mpl::contains<
			Types,
			recursive_type
		>,
		recursive_type,
		Element
	>::type type;
#endif
	typedef Element type;
};

}
}
}

#endif
