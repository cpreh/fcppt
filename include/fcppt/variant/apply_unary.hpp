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


#ifndef SGE_VARIANT_APPLY_UNARY_HPP_INCLUDED
#define SGE_VARIANT_APPLY_UNARY_HPP_INCLUDED

#include <sge/variant/size_type.hpp>
#include <sge/variant/detail/apply.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/empty.hpp>

namespace sge
{
namespace variant
{

template<
	typename Operation,
	typename Variant
>
typename Operation::result_type
apply_unary(
	Operation const &op,
	Variant const &obj
)
{
	typedef typename Variant::types types;

	return detail::apply<
		boost::mpl::integral_c<
			size_type,
			0
		>,
		boost::mpl::empty<
			types
		>::value
	>::execute(
		static_cast<
			typename boost::mpl::begin<
				types
			>::type *
		>(0),
		static_cast<
			typename boost::mpl::end<
				types
			>::type *
		>(0),
		op,
		obj
	);
}

}
}

#endif
