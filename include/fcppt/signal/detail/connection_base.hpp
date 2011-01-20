//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_CONNECTION_BASE_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_CONNECTION_BASE_HPP_INCLUDED

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
> connection_base;

}
}
}

#endif
