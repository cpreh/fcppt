//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OPTIONAL_REF_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OPTIONAL_REF_FWD_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

template<
	typename Tree
>
struct optional_ref
{
	static_assert(
		fcppt::container::tree::is_object<
			typename std::remove_cv<
				Tree
			>::type
		>::value,
		"Tree must be an fcppt::container::tree::object"
	);

	typedef fcppt::optional<
		Tree &
	> type;
};

}
}
}

#endif
