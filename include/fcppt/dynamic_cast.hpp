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


#ifndef FCPPT_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/type_info.hpp>
#include <fcppt/bad_dynamic_cast.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/utility/enable_if.hpp>
#include <typeinfo>
#include <stdexcept>

namespace fcppt
{

template<
	typename Dest,
	typename Src
>
typename boost::enable_if<
	boost::is_reference<
		Dest
	>,
	Dest
>::type
dynamic_cast_(
	Src &src
)
{
	try
	{
		return
			dynamic_cast<
				Dest
			>(
				src
			);
	}
	catch(
		std::bad_cast const &
	)
	{
		throw
			bad_dynamic_cast(
				type_info(
					typeid(
						Src
					)
				),
				type_info(
					typeid(
						Dest
					)
				)
			);	
	}
}

template<
	typename Dest,
	typename Src
>
typename boost::enable_if<
	boost::is_reference<
		Dest
	>,
	Dest
>::type
dynamic_cast_(
	Src const &src
)
{
	return
		dynamic_cast_<
			Dest
		>(
			const_cast<
				Src &
			>(
				src
			)
		);
}

template<
	typename Dest,
	typename Src
>
typename boost::enable_if<
	boost::is_pointer<
		Dest
	>,
	Dest
>::type
dynamic_cast_(
	Src const src
)
{
	return
		dynamic_cast<
			Dest
		>(
			src
		);
}

}

#endif
