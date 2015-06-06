//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_FUNCTION_POINTER_TO_REFERENCE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_FUNCTION_POINTER_TO_REFERENCE_HPP_INCLUDED

#include <fcppt/type_traits/detail/function_pointer_to_reference.hpp>


namespace fcppt
{
namespace type_traits
{

template<
	typename Type
>
using
function_pointer_to_reference
=
typename
fcppt::type_traits::detail::function_pointer_to_reference<
	Type
>::type;

}
}

#endif
