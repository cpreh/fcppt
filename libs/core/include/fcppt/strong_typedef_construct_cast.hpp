//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRONG_TYPEDEF_CONSTRUCT_CAST_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_CONSTRUCT_CAST_HPP_INCLUDED

#include <fcppt/is_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep
#include <fcppt/cast/apply.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt
{
/**
\brief Applies a cast from fcppt.cast and then construct the strong typedef

\ingroup fcpptstrongtypedef
*/
template <typename StrongTypedef, typename Conv, typename Arg>
constexpr StrongTypedef strong_typedef_construct_cast(Arg const &_arg)
  requires fcppt::is_strong_typedef<StrongTypedef>::value
{
  return StrongTypedef(
      fcppt::cast::apply<Conv, fcppt::type_traits::value_type<StrongTypedef>>(_arg));
}
}

#endif
