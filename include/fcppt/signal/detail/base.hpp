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


#ifndef SGE_SIGNAL_DETAIL_BASE_HPP_INCLUDED
#define SGE_SIGNAL_DETAIL_BASE_HPP_INCLUDED

#include <sge/signal/detail/concrete_connection.hpp>
#include <sge/signal/auto_connection.hpp>
#include <sge/noncopyable.hpp>
#include <sge/function/object.hpp>
#include <boost/intrusive/list.hpp>

namespace sge
{
namespace signal
{
namespace detail
{
template<typename T>
class base
{
	SGE_NONCOPYABLE(base)
public:
	typedef T function_signature;
	typedef sge::function::object<T> function_type;
	typedef detail::concrete_connection<
			function_signature
		> concrete_connection;

	auto_connection connect(function_type const &f);
protected:
	typedef boost::intrusive::list<
		concrete_connection,
		boost::intrusive::constant_time_size<
			false
		>
	> connection_list;

	base();
	connection_list &connections();
private:
	connection_list connections_;
};
}
}
}

#endif
