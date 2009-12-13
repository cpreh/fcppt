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


#ifndef SGE_SIGNAL_DETAIL_CONNECTION_HPP_INCLUDED
#define SGE_SIGNAL_DETAIL_CONNECTION_HPP_INCLUDED

#include <sge/noncopyable.hpp>
#include <sge/export.hpp>
#include <boost/intrusive/list_hook.hpp>
#include <boost/intrusive/link_mode.hpp>

namespace sge
{
namespace signal
{

namespace detail
{

typedef boost::intrusive::list_base_hook<
	boost::intrusive::link_mode<
		boost::intrusive::auto_unlink
	>
> object_base_hook;

// this class is intentionally left blank
class connection : public object_base_hook
{
	SGE_NONCOPYABLE(connection)
public:
	SGE_SYMBOL connection();
};

}
}
}

#endif
