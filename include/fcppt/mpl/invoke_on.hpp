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


#ifndef SGE_MPL_INVOKE_ON_HPP_INCLUDED
#define SGE_MPL_INVOKE_ON_HPP_INCLUDED

#include <sge/mpl/detail/invoke_on.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/empty.hpp>

namespace sge
{
namespace mpl
{

template<
	typename Sequence,
	typename Function,
	typename Index
>
typename Function::result_type
invoke_on(
	Index const &index,
	Function const &fun
)
{
	return detail::invoke_on<
		boost::mpl::integral_c<
			Index,
			0
		>,
		boost::mpl::empty<
			Sequence
		>::value
	>::execute(
		static_cast<
			typename boost::mpl::begin<
				Sequence
			>::type *
		>(0),
		static_cast<
			typename boost::mpl::end<
				Sequence
			>::type *
		>(0),
		index,
		fun
	);
}

}
}

#endif
