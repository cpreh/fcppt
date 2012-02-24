//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert/error.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/src/log/tree_formatter.hpp>
#include <fcppt/variant/object_impl.hpp>


fcppt::log::format::function const
fcppt::log::tree_formatter(
	fcppt::log::detail::context_tree const *_node,
	fcppt::log::format::function const &_formatter
)
{
	FCPPT_ASSERT_ERROR(
		_node
	);

	FCPPT_ASSERT_ERROR(
		_node->has_parent()
	);

	_node = &_node->parent();

	fcppt::log::format::function ret(
		_formatter
	);

	for(
		;
		_node->has_parent();
		_node = &_node->parent()
	)
		ret =
			fcppt::log::format::create_chain(
				fcppt::log::format::create_prefix(
					_node->value().get().get<
						fcppt::log::detail::inner_context_node
					>().name()
				),
				ret
			);

	FCPPT_ASSERT_ERROR(
		ret
	);

	return ret;
}
