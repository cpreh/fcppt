//          Copyright Carl Philipp Reh 2009 - 2016.
//          Copyright Philipp Middendorf 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_BASE_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_BASE_IMPL_HPP_INCLUDED

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/base_decl.hpp>
#include <fcppt/signal/connection.hpp>
#include <fcppt/signal/detail/concrete_connection_impl.hpp>


template<
	typename T
>
fcppt::signal::auto_connection
fcppt::signal::base<
	T
>::connect(
	function const &_function
)
{
	fcppt::signal::auto_connection con(
		fcppt::unique_ptr_to_base<
			fcppt::signal::connection
		>(
			fcppt::make_unique_ptr<
				concrete_connection
			>(
				_function
			)
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
		con;
}

template<
	typename T
>
bool
fcppt::signal::base<
	T
>::empty() const
{
	return
		connections_.empty();
}

template<
	typename T
>
fcppt::signal::base<
	T
>::base()
:
	connections_()
{
}

template<
	typename T
>
fcppt::signal::base<
	T
>::base(
	base &&
) = default;

template<
	typename T
>
fcppt::signal::base<
	T
> &
fcppt::signal::base<
	T
>::operator=(
	base &&
) = default;

template<
	typename T
>
fcppt::signal::base<
	T
>::~base()
{
}

template<
	typename T
>
typename fcppt::signal::base<
	T
>::connection_list &
fcppt::signal::base<
	T
>::connections() const
{
	return
		connections_;
}

#endif
