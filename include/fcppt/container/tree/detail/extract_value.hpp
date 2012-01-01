//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DETAIL_EXTRACT_VALUE_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_EXTRACT_VALUE_HPP_INCLUDED

#include <fcppt/scoped_ptr_impl.hpp>

namespace fcppt
{
namespace container
{
namespace tree
{
namespace detail
{

template<
	typename Arg
>
Arg &
extract_value(
	fcppt::scoped_ptr<
		Arg
	> &_value
)
{
	return *_value;
}

template<
	typename Arg
>
Arg const &
extract_value(
	fcppt::scoped_ptr<
		Arg
	> const &_value
)
{
	return *_value;
}

template<
	typename Arg
>
Arg &
extract_value(
	Arg &_value
)
{
	return _value;
}

}
}
}
}

#endif
