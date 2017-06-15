//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_PRINT_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_PRINT_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/container/tree/detail/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

template<
	typename Ch,
	typename Traits,
	typename Value
>
std::basic_ostream<
	Ch,
	Traits
> &
print(
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
		0u
	);

	return
		_stream;
}

}
}
}

#endif
