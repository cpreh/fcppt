//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OUTPUT_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OUTPUT_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/container/tree/detail/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

/**
\brief Outputs a tree.

\ingroup fcpptcontainertree
*/
template<
	typename Ch,
	typename Traits,
	typename Value
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::container::tree::object<
		Value
	> const &_tree
)
{
	fcppt::container::tree::detail::print(
		_stream,
		_tree,
		0U
	);

	return
		_stream;
}

}
}
}

#endif
