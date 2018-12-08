//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_STD_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_STD_TYPE_HPP_INCLUDED

#include <fcppt/variant/detail/std_type_impl.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types
>
using
std_type
=
typename
fcppt::variant::detail::std_type_impl<
	Types
>::type;

}
}
}

#endif
