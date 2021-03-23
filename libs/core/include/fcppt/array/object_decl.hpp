//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_ARRAY_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
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
  using impl_type = std::array<T, Size>;
  using value_type = typename impl_type::value_type;
  using reference = typename impl_type::reference;
  using const_reference = typename impl_type::const_reference;
  using size_type = typename impl_type::size_type;
  using iterator = typename impl_type::iterator;
  using const_iterator = typename impl_type::const_iterator;
  using pointer = typename impl_type::pointer;
  using const_pointer = typename impl_type::const_pointer;

  template <
      typename... Args,
      typename = std::enable_if_t<
          Size == sizeof...(Args) &&
          std::conjunction_v<std::is_constructible<T, Args>...>>>
  constexpr explicit object(Args &&...) noexcept(
      std::conjunction_v<std::is_nothrow_constructible<T, Args>...>);

  explicit object(fcppt::no_init const &);

  [[nodiscard]] reference get_unsafe(size_type) noexcept;
  [[nodiscard]] const_reference get_unsafe(size_type) const noexcept;

  [[nodiscard]] iterator begin();
  [[nodiscard]] iterator end();

  [[nodiscard]] const_iterator begin() const;
  [[nodiscard]] const_iterator end() const;

  [[nodiscard]] pointer data();
  [[nodiscard]] const_pointer data() const;

  [[nodiscard]] constexpr size_type size() const;

  [[nodiscard]] constexpr impl_type &impl() noexcept;
  [[nodiscard]] constexpr impl_type const &impl() const noexcept;
private:
  impl_type impl_;
};

FCPPT_PP_POP_WARNING

}

#endif
