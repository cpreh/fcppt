//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert/error.hpp>
#include <fcppt/log/detail/const_optional_context_tree_ref.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/log/format/prefix.hpp>
#include <fcppt/log/impl/tree_formatter.hpp>
#include <fcppt/variant/get_exn.hpp>


fcppt::log::format::optional_function
fcppt::log::impl::tree_formatter(
	fcppt::log::detail::context_tree const &_node,
	fcppt::log::format::optional_function const &_formatter
)
{
	fcppt::log::detail::const_optional_context_tree_ref cur(
		_node.parent()
	);

	FCPPT_ASSERT_ERROR(
		cur.has_value()
	);

	fcppt::log::format::optional_function ret;

	// TODO: This code is terrible.
	for(
		;
		cur.get_unsafe().get().parent().has_value();
		cur = cur.get_unsafe().get().parent()
	)
		ret =
			fcppt::log::format::optional_function(
				fcppt::log::format::chain(
					fcppt::log::format::optional_function(
						fcppt::log::format::prefix(
							fcppt::variant::get_exn<
								fcppt::log::detail::inner_context_node
							>(
								cur.get_unsafe().get().value().get()
							).name()
						)
					),
					ret
				)
			);

	return
		fcppt::log::format::chain(
			_formatter,
			ret
		);
}
