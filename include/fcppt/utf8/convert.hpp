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


#ifndef SGE_UTF8_CONVERT_HPP_INCLUDED
#define SGE_UTF8_CONVERT_HPP_INCLUDED

#include <sge/utf8/string.hpp>
#include <sge/string.hpp>
#include <sge/export.hpp>

namespace sge
{
namespace utf8
{

SGE_SYMBOL sge::string const
convert(
	utf8::string const &);

SGE_SYMBOL utf8::string const
convert(
	sge::string const &);

}
}

#endif
