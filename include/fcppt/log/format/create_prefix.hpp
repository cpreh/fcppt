//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CREATE_PREFIX_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CREATE_PREFIX_HPP_INCLUDED

#include <fcppt/log/format/const_object_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{
namespace format
{

/// Creates a formatter that will output @a prefix in front
FCPPT_SYMBOL const_object_ptr const
create_prefix(
	string const &prefix
);

}
}
}

#endif
