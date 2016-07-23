//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/location_setting.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/impl/find_child.hpp>
#include <fcppt/log/impl/find_or_create_child.hpp>
#include <fcppt/optional/maybe_void.hpp>


fcppt::log::context::context(
	fcppt::log::setting const &_root_setting
)
:
	tree_(
		fcppt::log::detail::context_tree_node(
			fcppt::log::name{
				fcppt::string()
			},
			_root_setting
		)
	)
{
}

fcppt::log::context::~context()
{
}

void
fcppt::log::context::set(
	fcppt::log::location_setting const &_location_setting
)
{
	for(
		fcppt::log::detail::context_tree &node
		:
		// TODO: Add make_pre_order
		fcppt::container::tree::pre_order<
			fcppt::log::detail::context_tree
		>(
			this->find_location(
				_location_setting.location()
			)
		)
	)
		node.value().setting(
			_location_setting.setting()
		);
}

fcppt::log::setting const &
fcppt::log::context::get(
	fcppt::log::location const &_location
) const
{
	// TODO: We need something like fold_break
	fcppt::reference<
		fcppt::log::detail::context_tree const
	> cur{
		fcppt::make_cref(
			tree_
		)
	};

	for(
		fcppt::string const &item
		:
		_location
	)
	{
		fcppt::log::impl::optional_context_tree_ref const result{
			fcppt::log::impl::find_child(
				// TODO: Make find_child more generic
				const_cast<
					fcppt::log::detail::context_tree &
				>(
					cur.get()
				),
				fcppt::log::name{
					item
				}
			)
		};

		if(
			!result.has_value()
		)
			break;

		fcppt::optional::maybe_void(
			result,
			[
				&cur
			](
				fcppt::reference<
					fcppt::log::detail::context_tree
				> const _cur
			)
			{
				cur =
					fcppt::make_cref(
						_cur.get()
					);
			}
		);
	}

	return
		cur.get().value().setting();
}

fcppt::log::detail::context_tree &
fcppt::log::context::root()
{
	return
		tree_;
}

fcppt::log::detail::context_tree &
fcppt::log::context::find_location(
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
					fcppt::make_ref(
						fcppt::log::impl::find_or_create_child(
							_cur.get(),
							fcppt::log::name{
								_item
							}
						)
					);
			}
		).get();
}
