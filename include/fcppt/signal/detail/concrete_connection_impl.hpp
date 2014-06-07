//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_CONCRETE_CONNECTION_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_CONCRETE_CONNECTION_IMPL_HPP_INCLUDED

#include <fcppt/signal/detail/concrete_connection.hpp>


template<
	typename T
>
fcppt::signal::detail::concrete_connection<
	T
>::concrete_connection(
	function_type const &_function
)
:
	fcppt::signal::connection(),
	function_(
		_function
	)
{
}

template<
	typename T
>
fcppt::signal::detail::concrete_connection<
	T
>::~concrete_connection()
{
}

template<
	typename T
>
typename fcppt::signal::detail::concrete_connection<
	T
>::function_type &
fcppt::signal::detail::concrete_connection<
	T
>::function()
{
	return function_;
}

#endif
