//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_CONNECTION_HPP_INCLUDED

#include <fcppt/signal/detail/connection_base.hpp>
#include <fcppt/class_symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace signal
{
namespace detail
{

// this class is intentionally left blank
class FCPPT_CLASS_SYMBOL connection
:
	public detail::connection_base
{
	FCPPT_NONCOPYABLE(
		connection
	);
public:
	FCPPT_SYMBOL
	connection();

	FCPPT_SYMBOL
	virtual ~connection();
};

}
}
}

#endif
