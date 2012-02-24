//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_GLOBAL_HPP_INCLUDED
#define FCPPT_LOG_GLOBAL_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/object_fwd.hpp>


namespace fcppt
{
namespace log
{

/**
\brief fcppt's own root logger

Instead of using fcppt's logger, you are encouraged to declare and use your
own.
*/
FCPPT_SYMBOL
fcppt::log::object &
global();

}
}

#endif
