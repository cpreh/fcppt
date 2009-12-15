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


#ifndef FCPPT_LOG_PARAMETERS_ROOT_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_ROOT_HPP_INCLUDED

#include <fcppt/log/parameters/root_fwd.hpp>
#include <fcppt/log/parameters/all_fwd.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{
namespace parameters
{

class root {
public:
	FCPPT_SYMBOL explicit root(
		io::ostream &
	);

	FCPPT_SYMBOL root
	prefix(
		string const &
	);

	FCPPT_SYMBOL root
	enabled(
		bool
	);

	FCPPT_SYMBOL root
	level(
		log::level::type
	);

	FCPPT_SYMBOL root
	context(
		log::context &
	);

	FCPPT_SYMBOL all const
	create() const;
private:
	io::ostream &sink_;

	string prefix_;

	bool enabled_;

	log::level::type level_;

	log::context *context_;
};

}
}
}

#endif
