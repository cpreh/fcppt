//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "tree_formatter.hpp"
#include <fcppt/assert/error.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/variant/object_impl.hpp>


fcppt::log::format::const_object_ptr const
fcppt::log::tree_formatter(
	log::context_location const &_context_location,
	log::format::const_object_ptr const _formatter
)
{
	log::detail::context_tree const *node(
		_context_location.context().find_node(
			_context_location.location()
		)
	);

	FCPPT_ASSERT_ERROR(
		node != 0
	);

	FCPPT_ASSERT_ERROR(
		node->has_parent()
	);

	node = &node->parent();

	log::format::const_object_ptr ret(
		_formatter
	);

	for(
		;
		node->has_parent();
		node = &node->parent()
	)
		ret =
			log::format::create_chain(
				log::format::create_prefix(
					node->value().get<
						log::detail::inner_context_node
					>().name()
				),
				ret
			);

	FCPPT_ASSERT_ERROR(
		ret
	);

	return ret;
}
