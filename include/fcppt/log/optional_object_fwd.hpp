//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_OPTIONAL_OBJECT_FWD_HPP_INCLUDED
#define FCPPT_LOG_OPTIONAL_OBJECT_FWD_HPP_INCLUDED

#include <fcppt/log/object_fwd.hpp>
#include <fcppt/optional_fwd.hpp>

namespace fcppt
{
namespace log
{

typedef fcppt::optional<
	log::object &
> optional_object;

}
}

#endif
