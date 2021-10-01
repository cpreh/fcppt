//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_IMPL_TREE_FORMATTER_HPP_INCLUDED
#define FCPPT_LOG_IMPL_TREE_FORMATTER_HPP_INCLUDED

#include <fcppt/log/detail/context_tree_fwd.hpp>
#include <fcppt/log/format/optional_function.hpp>

namespace fcppt::log::impl
{
fcppt::log::format::optional_function tree_formatter(fcppt::log::detail::context_tree const &);

}

#endif
