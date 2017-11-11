//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_IMPL_OPTIONAL_CONTEXT_TREE_REF_FWD_HPP_INCLUDED
#define FCPPT_LOG_IMPL_OPTIONAL_CONTEXT_TREE_REF_FWD_HPP_INCLUDED

#include <fcppt/log/detail/context_tree_fwd.hpp>
#include <fcppt/optional/reference_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace impl
{

typedef
fcppt::optional::reference<
	fcppt::log::detail::context_tree
>
optional_context_tree_ref;

}
}
}

#endif
