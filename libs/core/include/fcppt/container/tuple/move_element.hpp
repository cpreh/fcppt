//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_MOVE_ELEMENT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_MOVE_ELEMENT_HPP_INCLUDED

#include <fcppt/not.hpp>
#include <fcppt/container/tuple/type_at.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tuple
{

/**
\brief If a tuple element should be moved.

\ingroup fcpptcontainertuple

In fcppt, an element of a struct is moved if and only if the struct itself is
not an lvalue reference. For tuples, however, the situation is slighly more
complicated. Tuples can be used to perfectly forward arguments using
<code>std::forward_as_tuple</code>, which actually stores lvalue or rvalue
references in a tuple.

\tparam Tuple Must be a <code>std::tuple</code>.
*/
template<
	typename Tuple,
	std::size_t Index
>
using
move_element
=
std::integral_constant<
	bool,
	fcppt::not_(
		std::is_lvalue_reference<
			Tuple
		>::value
		||
		std::is_lvalue_reference<
			fcppt::container::tuple::type_at<
				fcppt::type_traits::remove_cv_ref_t<
					Tuple
				>,
				Index
			>
		>::value
	)
	||
	std::is_rvalue_reference<
		fcppt::container::tuple::type_at<
			fcppt::type_traits::remove_cv_ref_t<
				Tuple
			>,
			Index
		>
	>::value
>;

}
}
}

#endif
