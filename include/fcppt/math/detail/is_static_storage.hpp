//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_IS_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_IS_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/type_traits/is_std_array.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Type
>
using
is_static_storage
=
fcppt::type_traits::is_std_array<
	Type
>;

}
}
}

#endif
