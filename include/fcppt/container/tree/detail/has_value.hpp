//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DETAIL_HAS_VALUE_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_HAS_VALUE_HPP_INCLUDED

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
bool
has_value(
	fcppt::scoped_ptr<
		Arg
	> const &_value
)
{
	return
		static_cast<
			bool
		>(
			_value
		);
}

template<
	typename Arg
>
bool
has_value(
	Arg const &
)
{
	return true;
}

}
}
}
}

#endif
