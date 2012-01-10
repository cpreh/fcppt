//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_TREE_FORMATTER_HPP_INCLUDED
#define FCPPT_SRC_LOG_TREE_FORMATTER_HPP_INCLUDED

#include <fcppt/log/context_location_fwd.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>


namespace fcppt
{
namespace log
{

log::format::const_object_ptr const
tree_formatter(
	log::context_location const &,
	log::format::const_object_ptr
);

}
}

#endif
