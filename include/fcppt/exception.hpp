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


#ifndef FCPPT_EXCEPTION_HPP_INCLUDED
#define FCPPT_EXCEPTION_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/class_symbol.hpp>
#include <fcppt/string.hpp>
#include <exception>

namespace fcppt
{

/**
 * @brief The base class for all exceptions.
 *
 * fcppt::exception is a wrapper around an exception
 * that uses fcppt::string to store the error message.
 * Note that you will have to use fcppt::exception::string
 * to obtain the string. If you use what() nothing useful
 * will be given.
*/
class FCPPT_CLASS_SYMBOL exception
:
	public std::exception
{
public:
	FCPPT_SYMBOL explicit exception(
		fcppt::string const &
	);

	FCPPT_SYMBOL exception(
		exception const &
	);

	FCPPT_SYMBOL exception &
	operator=(
		exception const &
	);

	FCPPT_SYMBOL fcppt::string const &
	string() const;

	FCPPT_SYMBOL char const *
	what() const throw();

	FCPPT_SYMBOL virtual ~exception() throw();
private:
	fcppt::string s;
};

}

#endif
