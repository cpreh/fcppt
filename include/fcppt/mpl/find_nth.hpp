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


#ifndef SGE_MPL_FIND_NTH_HPP_INCLUDED
#define SGE_MPL_FIND_NTH_HPP_INCLUDED

#include <boost/mpl/advance.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/iter_fold.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/type_traits/is_same.hpp>

namespace sge
{
namespace mpl
{

template<
	typename Elements,
	typename Element,
	typename Number
>
class find_nth
:
public boost::mpl::deref<
	typename boost::mpl::advance<
		typename boost::mpl::begin<
			typename boost::mpl::iter_fold<
				Elements,
				boost::mpl::vector0<>,
				boost::mpl::if_<
					boost::is_same<
						Element,
						boost::mpl::deref<
							boost::mpl::_2
						>
					>,
					boost::mpl::push_back<
						boost::mpl::_1,
						boost::mpl::_2
					>,
					boost::mpl::_1
				>
			>::type
		>::type,
		Number
	>::type
>
{};

}
}

#endif
