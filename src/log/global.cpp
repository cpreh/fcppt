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


#include <fcppt/log/global.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/global_context.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cout.hpp>

fcppt::log::object &
fcppt::log::global()
{
	static object global_(
		parameters::root(
			cout
		)
		.prefix(
			FCPPT_TEXT("fcppt")
		)
		.enabled(
			true
		)
		.level(
			log::level::warning
		)
		.context(
			global_context()
		)
		.create()
	);

	return global_;
}
