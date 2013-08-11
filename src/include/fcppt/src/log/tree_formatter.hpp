//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_TREE_FORMATTER_HPP_INCLUDED
#define FCPPT_SRC_LOG_TREE_FORMATTER_HPP_INCLUDED

#include <fcppt/log/detail/optional_context_tree_ref.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{

fcppt::log::format::function
tree_formatter(
	fcppt::log::detail::optional_context_tree_ref,
	fcppt::log::format::function const &
);

}
}

#endif
