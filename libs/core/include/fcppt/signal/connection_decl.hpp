//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_CONNECTION_DECL_HPP_INCLUDED
#define FCPPT_SIGNAL_CONNECTION_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/connection_fwd.hpp>


namespace fcppt
{
namespace signal
{

/**
\brief A connection returned by a connect call

\ingroup fcpptsignal

This class must be held onto as long as the connection to the signal should be
established.
*/
class connection
{
	FCPPT_NONCOPYABLE(
		connection
	);
protected:
	connection();
public:
	virtual
	~connection() = 0;
};

}
}

#endif
