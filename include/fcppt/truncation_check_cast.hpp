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


#ifndef FCPPT_TRUNCATION_CHECK_CAST_HPP_INCLUDED
#define FCPPT_TRUNCATION_CHECK_CAST_HPP_INCLUDED

#include <fcppt/bad_truncation_check_cast.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <boost/utility/enable_if.hpp>
#include <typeinfo>

namespace fcppt
{

template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_fundamental<
			Source
		>,
		boost::is_fundamental<
			Dest
		>
	>,
	Dest
>::type
truncation_check_cast(
	Source const source
)
{
	Dest const dest(
		static_cast<
			Dest
		>(
			source
		)
	);

	if(
		static_cast<
			Source
		>(
			dest
		)
		!= source
	)
		throw bad_truncation_check_cast(
			typeid(Source),
			typeid(Dest)
		);
	
	return dest;
}

}

#endif
