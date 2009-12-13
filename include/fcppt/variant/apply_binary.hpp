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


#ifndef SGE_VARIANT_APPLY_BINARY_HPP_INCLUDED
#define SGE_VARIANT_APPLY_BINARY_HPP_INCLUDED

#include <sge/variant/apply_unary.hpp>
#include <sge/variant/detail/binary_unwrap.hpp>

namespace sge
{
namespace variant
{

template<
	typename Operation,
	typename Variant1,
	typename Variant2
>
typename Operation::result_type
apply_binary(
	Operation const &op,
	Variant1 const &obj1,
	Variant2 const &obj2)
{
	return apply_unary(
		detail::binary_unwrap<
			Operation,
			Variant1
		>(
			op,
			obj1
		),
		obj2
	);
}

}
}

#endif
