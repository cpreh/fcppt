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


#ifndef SGE_ASSERT_HPP_INCLUDED
#define SGE_ASSERT_HPP_INCLUDED

#include <sge/preprocessor/stringize.hpp>
#include <sge/preprocessor/file.hpp>
#include <sge/string.hpp>
#include <sge/export.hpp>

// TODO: split this!

namespace sge
{
namespace detail
{
SGE_SYMBOL void process_assert(
	string const &file,
	string const &line,
	string const &condition,
	string const &message = string(),
	string const &function = string());
}
}

#define SGE_ASSERT_MESSAGE(cond,message)\
if (!(cond))\
	sge::detail::process_assert(\
		SGE_PP_FILE,\
		SGE_PP_STRINGIZE(__LINE__),\
		SGE_PP_STRINGIZE(cond),\
		message);

#define SGE_ASSERT(cond)\
if (!(cond))\
	sge::detail::process_assert(\
		SGE_PP_FILE,\
		SGE_PP_STRINGIZE(__LINE__),\
		SGE_PP_STRINGIZE(cond));

#endif
