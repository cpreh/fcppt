//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_RAW_POINTER_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_RAW_POINTER_HPP_INCLUDED

#include <fcppt/type_traits/detail/is_raw_pointer.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if a pointer is a raw pointer type.

A raw pointer is a (cv qualified) pointer to <code>char</code> or to
<code>unsigned char</code>. Both can be used to read and write bytes.

\ingroup fcpptypetraits

\tparam Type Must be a pointer type.
*/
template<
	typename Type
>
using
is_raw_pointer
=
typename
fcppt::type_traits::detail::is_raw_pointer<
	Type
>::type;

}
}

#endif
