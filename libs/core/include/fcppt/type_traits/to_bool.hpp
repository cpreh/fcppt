//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_TO_BOOL_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_TO_BOOL_HPP_INCLUDED

#include <fcppt/cast/static_cast_fun.hpp>
#include <fcppt/type_traits/integral_cast.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Casts a std::integral_constant to bool.

\ingroup fcppttype_traits

\tparam Type A std::integral_constant.
*/
template<
	typename Type
>
using
to_bool
=
fcppt::type_traits::integral_cast<
	bool,
	fcppt::cast::static_cast_fun,
	Type
>;

}
}

#endif
