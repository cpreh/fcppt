//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_UNREGISTER_FUNCTION_HPP_INCLUDED
#define FCPPT_SIGNAL_UNREGISTER_FUNCTION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace signal
{
namespace unregister
{

/**
\brief The unregister function object
\ingroup fcpptsignal
*/
typedef std::function<
	void ()
> function;

}
}
}

#endif
