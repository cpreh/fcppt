//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_SAFE_INTEGRAL_CAST_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_SAFE_INTEGRAL_CAST_HPP_INCLUDED

#include <fcppt/type_traits/detail/safe_integral_cast.hpp>

namespace fcppt::type_traits
{
/**
\brief Casts std::integral_constants and checks for truncation.

\ingroup fcppttypetraits

\tparam DestType An integral type.

\tparam Src A std::integral_constant.
*/
template <typename DestType, typename Src>
using safe_integral_cast = fcppt::type_traits::detail::safe_integral_cast<DestType, Src>::type;
}

#endif
