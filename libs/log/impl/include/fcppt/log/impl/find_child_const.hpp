//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_IMPL_FIND_CHILD_CONST_HPP_INCLUDED
#define FCPPT_LOG_IMPL_FIND_CHILD_CONST_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/log/name_fwd.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>
#include <fcppt/log/impl/const_optional_context_tree_ref.hpp>

namespace fcppt
{
namespace log
{
namespace impl
{
fcppt::log::impl::const_optional_context_tree_ref find_child_const(
    fcppt::reference<fcppt::log::detail::context_tree const>, fcppt::log::name const &);

}
}
}

#endif
