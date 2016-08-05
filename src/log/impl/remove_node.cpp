//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/loop.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/container/tree/child_position.hpp>
#include <fcppt/container/tree/make_to_root.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/impl/remove_node.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


void
fcppt::log::impl::remove_node(
	fcppt::log::detail::context_tree &_node
)
{
	fcppt::algorithm::fold_break(
		fcppt::container::tree::make_to_root(
			FCPPT_ASSERT_OPTIONAL_ERROR(
				_node.parent()
			).get()
		),
		fcppt::make_ref(
			_node
		),
		[](
			fcppt::log::detail::context_tree &_parent,
			fcppt::reference<
				fcppt::log::detail::context_tree
			> const _child
		)
		{
			if(
				_child.get().value().ref_count()
				!=
				0u
				||
				!_child.get().empty()
			)
				return
					std::make_pair(
						fcppt::loop::break_,
						fcppt::make_ref(
							_parent
						)
					);

			_parent.erase(
				FCPPT_ASSERT_OPTIONAL_ERROR(
					fcppt::container::tree::child_position(
						_parent,
						_child.get()
					)
				)
			);

			return
				std::make_pair(
					fcppt::loop::continue_,
					fcppt::make_ref(
						_parent
					)
				);
		}
	);
}
