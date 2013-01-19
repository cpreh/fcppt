//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_CONNECTION_BASE_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_CONNECTION_BASE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/intrusive/link_mode.hpp>
#include <boost/intrusive/list_hook.hpp>
#include <fcppt/config/external_end.hpp>


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
