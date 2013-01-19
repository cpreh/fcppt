//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_FIND_LOCATION_HPP_INCLUDED
#define FCPPT_SRC_LOG_FIND_LOCATION_HPP_INCLUDED

#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>
#include <fcppt/log/detail/optional_context_tree_ref_fwd.hpp>


namespace fcppt
{
namespace log
{

fcppt::log::detail::optional_context_tree_ref const
find_location(
	fcppt::log::detail::context_tree &,
	fcppt::log::location const &
);

}
}

#endif
