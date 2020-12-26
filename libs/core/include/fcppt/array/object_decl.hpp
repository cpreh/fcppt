//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_ARRAY_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/array/object_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)
FCPPT_PP_DISABLE_VC_WARNING(5027)

template <typename T, std::size_t Size>
class object
{
public:
  using value_type = T;

  using impl_type = std::array<T, Size>;

  template <
      typename... Args,
      typename = std::enable_if_t<
          Size == sizeof...(Args) &&
          std::conjunction_v<std::is_constructible<T, Args>...>>>
  constexpr explicit object(Args &&...) noexcept(
      std::conjunction_v<std::is_nothrow_constructible<T, Args>...>);

  [[nodiscard]] constexpr impl_type &impl() noexcept;

  [[nodiscard]] constexpr impl_type const &impl() const noexcept;
private:
  impl_type impl_;
};

FCPPT_PP_POP_WARNING

}

#endif
