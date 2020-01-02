//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/fold.hpp>
#include <fcppt/container/tree/make_to_root.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/log/format/prefix.hpp>
#include <fcppt/log/format/prefix_string.hpp>
#include <fcppt/log/impl/tree_formatter.hpp>


fcppt::log::format::optional_function
fcppt::log::impl::tree_formatter(
	fcppt::log::detail::context_tree const &_node
)
{
	return
		fcppt::algorithm::fold(
			fcppt::container::tree::make_to_root(
				_node
			),
			fcppt::log::format::optional_function{},
			[](
				fcppt::log::detail::context_tree const &_cur,
				fcppt::log::format::optional_function const &_state
			)
			{
				fcppt::log::name const &name(
					_cur.value().name()
				);

				return
					name.get().empty()
					?
						_state
					:
						fcppt::log::format::optional_function(
							fcppt::log::format::chain(
								fcppt::log::format::optional_function(
									fcppt::log::format::prefix(
										fcppt::log::format::prefix_string{
											name.get()
										}
									)
								),
								_state
							)
						)
					;
			}
		);
}
