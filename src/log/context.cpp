//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/location_setting.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/impl/find_child_node.hpp>
#include <fcppt/optional/from.hpp>


fcppt::log::context::context(
	fcppt::log::setting const &_root_setting
)
:
	tree_(
		fcppt::log::detail::context_tree_node(
			fcppt::string(),
			_root_setting
		)
	)
{
}

fcppt::log::context::~context()
{
}

fcppt::log::detail::context_tree &
fcppt::log::context::add(
	fcppt::log::location const &_location
)
{
	return
		this->find_or_create(
			_location
		);
}

void
fcppt::log::context::remove(
	fcppt::log::detail::context_tree &
)
{
	// TODO: Add a reference counter and remove nodes that are no longer needed
}

void
fcppt::log::context::set(
	fcppt::log::location_setting const &_location_setting
)
{
	for(
		fcppt::log::detail::context_tree &node
		:
		fcppt::container::tree::pre_order<
			fcppt::log::detail::context_tree
		>(
			this->find_or_create(
				_location_setting.location()
			)
		)
	)
		node.value().setting(
			_location_setting.setting()
		);
}

fcppt::log::detail::context_tree &
fcppt::log::context::find_or_create(
	fcppt::log::location const &_location
)
{
	return
		fcppt::algorithm::fold(
			_location,
			fcppt::make_ref(
				tree_
			),
			[](
				fcppt::string const &_item,
				fcppt::reference<
					fcppt::log::detail::context_tree
				> const _cur
			)
			{
				return
					fcppt::optional::from(
						fcppt::log::impl::find_child_node(
							_cur.get(),
							_item
						),
						[
							_cur,
							&_item
						]{
							_cur.get().push_back(
								fcppt::log::detail::context_tree_node{
									_item,
									_cur.get().value().setting()
								}
							);

							return
								fcppt::make_ref(
									_cur.get().back()
								);
						}
					);
			}
		).get();
}
