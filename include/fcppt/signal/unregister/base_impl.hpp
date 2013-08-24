//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_UNREGISTER_BASE_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_UNREGISTER_BASE_IMPL_HPP_INCLUDED

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/unregister/base_decl.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/signal/unregister/detail/concrete_connection_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T
>
fcppt::signal::auto_connection
fcppt::signal::unregister::base<T>::connect(
	function_type const &_function,
	fcppt::signal::unregister::function const &_unregister
)
{
	auto_connection con(
		fcppt::make_unique_ptr<
			concrete_connection
		>(
			_function,
			_unregister
		)
	);

	connections_.push_back(
		fcppt::cast::static_downcast<
			concrete_connection &
		>(
			*con
		)
	);

	return
		std::move(
			con
		);
}

template<
	typename T
>
bool
fcppt::signal::unregister::base<T>::empty() const
{
	return connections().empty();
}

template<
	typename T
>
fcppt::signal::unregister::base<T>::base()
:
	connections_()
{
}

template<
	typename T
>
fcppt::signal::unregister::base<T>::~base()
{
}

template<
	typename T
>
typename fcppt::signal::unregister::base<T>::connection_list &
fcppt::signal::unregister::base<T>::connections() const
{
	return connections_;
}

#endif
