//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/maybe.hpp>
#include <fcppt/maybe_void.hpp>
#include <fcppt/optional_bind.hpp>
#include <fcppt/optional_bind_construct.hpp>
#include <fcppt/optional_to_exception.hpp>
#include <fcppt/reference_wrapper_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/container/tree/child_position.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/no_such_location.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_object.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/detail/context_tree_node_variant.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/log/impl/find_inner_node.hpp>
#include <fcppt/log/impl/find_location.hpp>
#include <fcppt/log/impl/find_logger_node.hpp>
#include <fcppt/log/impl/to_outer_node.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <vector>
#include <fcppt/config/external_end.hpp>


fcppt::log::context::context()
:
	tree_(
		fcppt::log::detail::context_tree_node(
			fcppt::log::detail::context_tree_node_variant{
				fcppt::log::detail::inner_context_node(
					fcppt::string()
				)
			}
		)
	)
{
}

fcppt::log::context::~context()
{
	if(
		!std::uncaught_exception()
	)
		FCPPT_ASSERT_PRE(
			tree_.empty()
		);
}

fcppt::log::optional_object
fcppt::log::context::find(
	fcppt::log::location const &_location
)
{
	return
		fcppt::optional_bind(
			fcppt::log::impl::find_location(
				tree_,
				_location
			),
			[](
				fcppt::log::detail::context_tree const &_tree_location
			)
			{
				return
					fcppt::optional_bind_construct(
						fcppt::log::impl::find_logger_node(
							_tree_location
						),
						[](
							fcppt::log::detail::outer_context_node const &_node
						)
						-> fcppt::log::object &
						{
							return
								_node.object();
						}
					);
			}
		);
}

void
fcppt::log::context::apply(
	fcppt::log::location const &_location,
	fcppt::log::tree_function const &_function
)
{
	this->apply_to(
		_function,
		fcppt::optional_to_exception(
			fcppt::log::impl::find_location(
				tree_,
				_location
			),
			[
				&_location
			]{
				return
					fcppt::log::no_such_location(
						_location
					);
			}
		)
	);
}

void
fcppt::log::context::apply_all(
	fcppt::log::tree_function const &_function
)
{
	this->apply_to(
		_function,
		tree_
	);
}

void
fcppt::log::context::transfer_to(
	fcppt::log::context &_other
)
{
	typedef
	std::vector<
		fcppt::log::detail::outer_context_node
	>
	outer_context_node_vector;

	outer_context_node_vector const nodes(
		fcppt::algorithm::map_optional<
			outer_context_node_vector
		>(
			fcppt::container::tree::pre_order<
				fcppt::log::detail::context_tree
			>(
				tree_
			),
			[](
				fcppt::log::detail::context_tree &_elem
			)
			{
				return
					fcppt::log::impl::to_outer_node(
						_elem
					);
			}
		)
	);

	for(
		auto const &node
		:
		nodes
	)
		node.object().transfer(
			_other
		);

	FCPPT_ASSERT_ERROR(
		tree_.empty()
	);
}

void
fcppt::log::context::apply_to(
	fcppt::log::tree_function const &_function,
	fcppt::log::detail::context_tree &_tree
)
{
	for(
		fcppt::log::detail::context_tree &elem
		:
		fcppt::container::tree::pre_order<
			fcppt::log::detail::context_tree
		>(
			_tree
		)
	)
		fcppt::maybe_void(
			fcppt::log::impl::to_outer_node(
				elem
			),
			[
				&_function
			](
				fcppt::log::detail::outer_context_node &_node
			)
			{
				_function(
					_node.object()
				);
			}
		);
}

fcppt::log::detail::context_tree &
fcppt::log::context::add(
	fcppt::log::location const &_location,
	fcppt::log::object &_object
)
{
	fcppt::reference_wrapper<
		fcppt::log::detail::context_tree
	> cur(
		tree_
	);

	for(
		fcppt::string const &item
		:
		_location
	)
		cur =
			fcppt::maybe(
				fcppt::log::impl::find_inner_node(
					cur.get(),
					item
				),
				[
					cur,
					&item
				]{
					cur.get().push_back(
						fcppt::log::detail::context_tree_node(
							fcppt::log::detail::context_tree_node_variant{
								fcppt::log::detail::inner_context_node(
									item
								)
							}
						)
					);

					return
						fcppt::make_ref(
							cur.get().back()
						);
				},
				[](
					fcppt::log::detail::context_tree &_node
				)
				{
					return
						fcppt::make_ref(
							_node
						);
				}
			);

	FCPPT_ASSERT_PRE(
		!fcppt::log::impl::find_logger_node(
			cur.get()
		).has_value()
	);

	cur.get().push_back(
		fcppt::log::detail::context_tree_node(
			fcppt::log::detail::context_tree_node_variant{
				fcppt::log::detail::outer_context_node(
					_object
				)
			}
		)
	);

	return
		cur.get().back();
}

void
fcppt::log::context::remove(
	fcppt::log::detail::context_tree &_tree
)
{
	// TODO: This code is terrible
	fcppt::log::detail::context_tree::optional_ref node(
		_tree.parent()
	);

	FCPPT_ASSERT_PRE(
		node.has_value()
	);

	node.get_unsafe().erase(
		fcppt::container::tree::child_position(
			node.get_unsafe(),
			_tree
		).get_unsafe()
	);

	while(
		node.get_unsafe().parent().has_value()
		&&
		node.get_unsafe().empty()
	)
	{
		fcppt::log::detail::context_tree::optional_ref const parent(
			node.get_unsafe().parent()
		);

		parent.get_unsafe().erase(
			fcppt::container::tree::child_position(
				parent.get_unsafe(),
				node.get_unsafe()
			).get_unsafe()
		);

		node =
			parent;
	}
}
