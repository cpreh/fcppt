//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_BIT_MASK_DECL_HPP_INCLUDED
#define FCPPT_BIT_MASK_DECL_HPP_INCLUDED

#include <fcppt/bit/mask_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::bit
{
/**
\brief A bit mask

\ingroup fcpptbit
*/
template <typename Type>
class mask
{
public:
  static_assert(std::is_integral_v<Type>, "Type must be integral");

  constexpr explicit mask(Type) noexcept;

  constexpr Type get() const noexcept;

private:
  Type value_;
};

}

#endif
