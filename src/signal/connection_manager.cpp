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


#include <fcppt/signal/connection_manager.hpp>

fcppt::signal::connection_manager::connection_manager()
:
	connections()
{}

fcppt::signal::connection_manager::connection_manager(
	container const &_connections)
:
	connections(_connections)
{}

void fcppt::signal::connection_manager::connect(
	shared_connection const &v)
{
	connections.push_back(
		v);
}

void fcppt::signal::connection_manager::connect(
	auto_connection v)
{
	connections.push_back(
		shared_connection(
			v));
}

void fcppt::signal::connection_manager::clear()
{
	connections.clear();
}
