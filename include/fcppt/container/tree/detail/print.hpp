//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DETAIL_PRINT_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_PRINT_HPP_INCLUDED

#include <fcppt/container/tree/object_impl.hpp>
#include <ostream>

namespace fcppt
{
namespace container
{
namespace tree
{
namespace detail
{

template<
	typename Ch,
	typename Traits,
	typename Value
>
void
print(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	tree::object<
		Value
	> const &_tree,
	unsigned const _indent
)
{
	for(
		unsigned index = 0;
		index < _indent;
		++index
	)
		_stream
			<< _stream.widen('\t');

	if(
		_tree.has_value()
	)
		_stream
			<< _tree.value()
			<< _stream.widen('\n');

	for(
		typename tree::object<
			Value
		>::const_iterator it(
			_tree.begin()
		);
		it != _tree.end();
		++it
	)
		tree::detail::print(
			_stream,
			*it,
			_indent + 1u
		);
}

}
}
}
}

#endif
