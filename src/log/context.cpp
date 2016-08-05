//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/loop.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/container/tree/make_pre_order.hpp>
#include <fcppt/log/const_level_stream_array_ref.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/impl/find_child_const.hpp>
#include <fcppt/log/impl/find_or_create_child.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::log::context::context(
	fcppt::log::setting const &_root_setting,
	fcppt::log::level_stream_array const &_streams
)
:
	tree_(
		fcppt::log::detail::context_tree_node(
			fcppt::log::name{
				fcppt::string()
			},
			_root_setting
		)
	),
	streams_(
		_streams
	)
{
}

fcppt::log::context::~context()
{
}

void
fcppt::log::context::set(
	fcppt::log::location const &_location,
	fcppt::log::setting const &_setting
)
{
	for(
		fcppt::log::detail::context_tree &node
		:
		fcppt::container::tree::make_pre_order(
			this->find_location(
				_location
			)
		)
	)
		node.value().setting(
			_setting
		);
}

fcppt::log::setting const &
fcppt::log::context::get(
	fcppt::log::location const &_location
) const
{
	return
		fcppt::algorithm::fold_break(
			_location,
			fcppt::make_cref(
				tree_
			),
			[](
				fcppt::string const &_item,
				fcppt::reference<
					fcppt::log::detail::context_tree const
				> const _cur
			)
			{
				return
					fcppt::optional::maybe(
						fcppt::log::impl::find_child_const(
							_cur.get(),
							fcppt::log::name{
								_item
							}
						),
						[
							_cur
						]{
							return
								std::make_pair(
									fcppt::loop::break_,
									_cur
								);
						},
						[](
							fcppt::reference<
								fcppt::log::detail::context_tree const
							> const _result
						)
						{
							return
								std::make_pair(
									fcppt::loop::continue_,
									_result
								);
						}
					);
			}
		).get().value().setting();
}

fcppt::log::const_level_stream_array_ref
fcppt::log::context::level_streams() const
{
	return
		fcppt::make_cref(
			streams_
		);
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
