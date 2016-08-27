//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_IMPL_FIND_CHILD_TPL_HPP_INCLUDED
#define FCPPT_LOG_IMPL_FIND_CHILD_TPL_HPP_INCLUDED

#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/container/tree/optional_ref.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/optional/deref.hpp>


namespace fcppt
{
namespace log
{
namespace impl
{

template<
	typename Tree
>
fcppt::container::tree::optional_ref<
	Tree
>
find_child_tpl(
	Tree &_tree,
	fcppt::log::name const &_name
)
{
	return
		fcppt::optional::deref(
			fcppt::algorithm::find_if_opt(
				_tree,
				[
					&_name
				](
					Tree &_child
				)
				{
					return
						_child.value().name()
						==
						_name;
				}
			)
		);
}

}
}
}

#endif
