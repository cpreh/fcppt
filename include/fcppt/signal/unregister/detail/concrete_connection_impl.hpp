//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_IMPL_HPP_INCLUDED

#include <fcppt/signal/connection.hpp>
#include <fcppt/signal/detail/connection_base.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/signal/unregister/detail/concrete_connection.hpp>


template<
	typename T
>
fcppt::signal::unregister::detail::concrete_connection<T>::concrete_connection(
	function_type const &_function,
	fcppt::signal::unregister::function const &_unregister
)
:
	fcppt::signal::connection(),
	function_(
		_function
	),
	unregister_(
		_unregister
	)
{
}

template<
	typename T
>
fcppt::signal::unregister::detail::concrete_connection<T>::~concrete_connection()
{
	this->signal::detail::connection_base::unlink();

	unregister_();
}

template<
	typename T
>
typename fcppt::signal::unregister::detail::concrete_connection<T>::function_type &
fcppt::signal::unregister::detail::concrete_connection<T>::function()
{
	return function_;
}

#endif
