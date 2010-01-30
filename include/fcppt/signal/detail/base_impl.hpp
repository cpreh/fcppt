//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_BASE_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_BASE_IMPL_HPP_INCLUDED

#include <fcppt/signal/detail/concrete_connection_impl.hpp>

template<typename T>
fcppt::signal::auto_connection
fcppt::signal::detail::base<T>::connect(
	function_type const &f)
{
	auto_connection a(
		new concrete_connection(f));
	connections_.push_back(static_cast<concrete_connection &>(*a));
	return a;
}

template<typename T>
fcppt::signal::detail::base<T>::base()
{}

template<typename T>
typename fcppt::signal::detail::base<T>::connection_list &
fcppt::signal::detail::base<T>::connections() const
{
	return connections_;
}

#endif
