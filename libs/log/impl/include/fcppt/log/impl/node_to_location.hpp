//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_IMPL_NODE_TO_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_IMPL_NODE_TO_LOCATION_HPP_INCLUDED

#include <fcppt/log/location.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>

namespace fcppt::log::impl
{
fcppt::log::location node_to_location(fcppt::log::detail::context_tree const &);

}

#endif
