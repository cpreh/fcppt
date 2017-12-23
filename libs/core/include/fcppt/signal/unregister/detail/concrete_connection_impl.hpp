//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_IMPL_HPP_INCLUDED

#include <fcppt/signal/connection_impl.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/signal/unregister/detail/concrete_connection_decl.hpp>


template<
	typename Function
>
fcppt::signal::unregister::detail::concrete_connection<
	Function
>::concrete_connection(
	list_type &_list,
	function_type const &_function,
	fcppt::signal::unregister::function const &_unregister
)
:
	fcppt::signal::connection{
		_list
	},
	function_{
		_function
	},
	unregister_(
		_unregister
	)
{
}

template<
	typename Function
>
fcppt::signal::unregister::detail::concrete_connection<
	Function
>::~concrete_connection()
{
	this->unlink();

	unregister_();
}

template<
	typename Function
>
typename
fcppt::signal::unregister::detail::concrete_connection<
	Function
>::function_type const &
fcppt::signal::unregister::detail::concrete_connection<
	Function
>::function() const
{
	return
		function_;
}

#endif
