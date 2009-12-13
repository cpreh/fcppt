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


#ifndef FCPPT_LOG_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_LOCATION_HPP_INCLUDED

#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/detail/location_vector.hpp>
#include <fcppt/string.hpp>
#include <fcppt/export.hpp>

namespace fcppt
{
namespace log
{

class location {
public:
	FCPPT_SYMBOL explicit location(
		fcppt::string const &
	);

	typedef detail::location_vector::const_iterator const_iterator;

	FCPPT_SYMBOL location &
	operator +=(
		fcppt::string const &
	);

	FCPPT_SYMBOL const_iterator
	begin() const;

	FCPPT_SYMBOL const_iterator
	end() const;

	FCPPT_SYMBOL fcppt::string const
	string() const;
private:
	detail::location_vector entries_;
};

FCPPT_SYMBOL location const
operator +(
	location,
	string const &
);

}
}

#endif
