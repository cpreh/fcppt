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


#ifndef FCPPT_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED
#define FCPPT_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/type_info.hpp>
#include <fcppt/class_symbol.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{

class FCPPT_CLASS_SYMBOL bad_truncation_check_cast
:
	public exception
{
public:
	FCPPT_SYMBOL bad_truncation_check_cast(
		type_info const &source,
		type_info const &dest
	);

	type_info const &
	source() const;

	type_info const &
	destination() const;
private:
	type_info
		source_,
		destination_;
};

}

#endif
