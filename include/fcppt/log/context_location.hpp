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


#ifndef FCPPT_LOG_CONTEXT_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_LOCATION_HPP_INCLUDED

#include <fcppt/log/context_location_fwd.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

class context_location {
public:
	FCPPT_SYMBOL context_location();

	FCPPT_SYMBOL context_location(
		log::context *,
		log::location const &
	);

	FCPPT_SYMBOL log::context *
	context() const;

	FCPPT_SYMBOL log::location const &
	location() const;
private:
	typedef optional<
		log::location
	> optional_location;

	log::context *context_;

	optional_location location_;
};

}
}

#endif
