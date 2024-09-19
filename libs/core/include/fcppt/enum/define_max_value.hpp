//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_DEFINE_MAX_VALUE_HPP_INCLUDED
#define FCPPT_ENUM_DEFINE_MAX_VALUE_HPP_INCLUDED

#include <fcppt/enum/max_value_impl_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits> // IWYU pragma: keep
#include <fcppt/config/external_end.hpp>

/**
\brief Specialize fcppt::enum_::max_value_impl using a macro.

\ingroup fcpptenum
*/
#define FCPPT_ENUM_DEFINE_MAX_VALUE(value) \
namespace fcppt::enum_ { \
template<> struct max_value_impl<decltype(value)> { \
  using type = std::integral_constant<decltype(value), value>; \
};\
}

#endif
