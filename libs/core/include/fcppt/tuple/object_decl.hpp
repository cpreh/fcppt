//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_TUPLE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/tuple/object_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)
FCPPT_PP_DISABLE_VC_WARNING(5027)

/**
\brief Like std::tuple but with a proper constructor.
\ingroup fcppttuple
*/
template <typename... Types>
class object
{
public:
  using impl_type = std::tuple<Types...>;

  template <typename... Args>
  constexpr explicit object(Args &&...) noexcept(
      std::conjunction_v<std::is_nothrow_constructible<Types, Args>...>)
    requires(
        sizeof...(Types) == sizeof...(Args) &&
        std::conjunction_v<std::is_constructible<Types, Args>...>);

  [[nodiscard]] constexpr impl_type &impl() noexcept;

  [[nodiscard]] constexpr impl_type const &impl() const noexcept;
private:
  impl_type impl_;
};

FCPPT_PP_POP_WARNING

}

#endif
