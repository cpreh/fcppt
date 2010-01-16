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


#ifndef FCPPT_SIGNAL_DETAIL_BASE_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_BASE_HPP_INCLUDED

#include <fcppt/signal/detail/concrete_connection.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/function/object.hpp>
#include <boost/intrusive/list.hpp>

namespace fcppt
{
namespace signal
{
namespace detail
{
template<typename T>
class base
{
	FCPPT_NONCOPYABLE(base)
public:
	typedef T function_signature;
	typedef fcppt::function::object<T> function_type;
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
	connection_list &connections() const;
private:
	mutable connection_list connections_;
};
}
}
}

#endif
