//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_GLOBAL_HPP_INCLUDED
#define FCPPT_LOG_GLOBAL_HPP_INCLUDED

#include <fcppt/log/object_fwd.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

/// fcppt's own logger root
FCPPT_SYMBOL object &
global();

}
}

#endif
