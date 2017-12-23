//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_CONNECTION_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_CONNECTION_IMPL_HPP_INCLUDED

#include <fcppt/intrusive/base_impl.hpp>
#include <fcppt/intrusive/list_fwd.hpp>
#include <fcppt/signal/connection_decl.hpp>


template<
	typename Type
>
inline
fcppt::signal::connection::connection(
	fcppt::intrusive::list<
		Type
	> &_list
)
:
	fcppt::intrusive::base{
		_list
	}
{
}

inline
fcppt::signal::connection::~connection()
{
}

#endif
