//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert/error.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/optional_context_tree_ref.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/src/log/tree_formatter.hpp>
#include <fcppt/variant/get_exn.hpp>


fcppt::log::format::function
fcppt::log::tree_formatter(
	fcppt::log::detail::optional_context_tree_ref _node,
	fcppt::log::format::function const &_formatter
)
{
	FCPPT_ASSERT_ERROR(
		_node.has_value()
	);

	_node = _node.get_unsafe().parent();

	FCPPT_ASSERT_ERROR(
		_node.has_value()
	);

	fcppt::log::format::function ret;

	for(
		;
		_node.get_unsafe().parent().has_value();
		_node = _node.get_unsafe().parent()
	)
		ret =
			fcppt::log::format::create_chain(
				fcppt::log::format::create_prefix(
					fcppt::variant::get_exn<
						fcppt::log::detail::inner_context_node
					>(
						_node.get_unsafe().value().get()
					).name()
				),
				ret
			);

	FCPPT_ASSERT_ERROR(
		ret
	);

	return
		fcppt::log::format::create_chain(
			_formatter,
			ret
		);
}
