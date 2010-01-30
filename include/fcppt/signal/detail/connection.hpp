//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_CONNECTION_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>
#include <boost/intrusive/list_hook.hpp>
#include <boost/intrusive/link_mode.hpp>

namespace fcppt
{
namespace signal
{

namespace detail
{

typedef boost::intrusive::list_base_hook<
	boost::intrusive::link_mode<
		boost::intrusive::auto_unlink
	>
> object_base_hook;

// this class is intentionally left blank
class connection : public object_base_hook
{
	FCPPT_NONCOPYABLE(connection)
public:
	FCPPT_SYMBOL connection();
};

}
}
}

#endif
