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


#ifndef SGE_UTF8_FACET_HPP_INCLUDED
#define SGE_UTF8_FACET_HPP_INCLUDED

#include <sge/export.hpp>

#define BOOST_UTF8_BEGIN_NAMESPACE \
namespace boost { \
namespace sge {

#define BOOST_UTF8_END_NAMESPACE }}

#define BOOST_UTF8_DECL SGE_CLASS_SYMBOL

#include <boost/detail/utf8_codecvt_facet.hpp>

namespace sge
{
namespace utf8
{

typedef ::boost::sge::utf8_codecvt_facet facet;

}
}

#endif
