//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_CONST_OPTIONAL_CONTEXT_TREE_REF_FWD_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_CONST_OPTIONAL_CONTEXT_TREE_REF_FWD_HPP_INCLUDED

#include <fcppt/container/tree/optional_ref_fwd.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

typedef
fcppt::container::tree::optional_ref<
	fcppt::log::detail::context_tree const
>
const_optional_context_tree_ref;

}
}
}

#endif
