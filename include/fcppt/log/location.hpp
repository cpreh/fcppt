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


#ifndef SGE_LOG_LOCATION_HPP_INCLUDED
#define SGE_LOG_LOCATION_HPP_INCLUDED

#include <sge/log/location_fwd.hpp>
#include <sge/log/detail/location_vector.hpp>
#include <sge/string.hpp>
#include <sge/export.hpp>

namespace sge
{
namespace log
{

class location {
public:
	SGE_SYMBOL explicit location(
		sge::string const &
	);

	typedef detail::location_vector::const_iterator const_iterator;

	SGE_SYMBOL location &
	operator +=(
		sge::string const &
	);

	SGE_SYMBOL const_iterator
	begin() const;

	SGE_SYMBOL const_iterator
	end() const;

	SGE_SYMBOL sge::string const
	string() const;
private:
	detail::location_vector entries_;
};

SGE_SYMBOL location const
operator +(
	location,
	string const &
);

}
}

#endif
