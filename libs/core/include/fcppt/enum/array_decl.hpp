//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_ARRAY_DECL_HPP_INCLUDED
#define FCPPT_ENUM_ARRAY_DECL_HPP_INCLUDED

#include <fcppt/array/object_impl.hpp>
#include <fcppt/enum/array_fwd.hpp> // IWYU pragma: keep
#include <fcppt/enum/size.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4623)
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief An array indexed with an enum

\ingroup fcpptenum

This class is like #fcppt::array::object, except that <code>operator[]</code>
takes a parameter of type \a Enum. This class is meant to be used with
contiguous enums.

\tparam Enum The enum type to use as an index which also determines the array's size.
*/
template <typename Enum, typename Value>
class array
{
public:
  using enum_type = Enum;

  using static_size = fcppt::enum_::size<Enum>;

  using internal = fcppt::array::object<Value, static_size::value>;

  template <typename... Args>
  constexpr explicit array(Args &&...) noexcept(
      std::conjunction_v<std::is_nothrow_constructible<Value, Args>...>)
    requires(
        fcppt::enum_::size<Enum>::value == sizeof...(Args) &&
        std::conjunction_v<std::is_constructible<Value, Args>...>);

  struct from_internal {};

  constexpr array(from_internal, internal &&) noexcept(std::is_nothrow_move_constructible_v<internal>);

  using value_type = internal::value_type;

  using reference = internal::reference;
  using const_reference = internal::const_reference;
  using iterator = internal::iterator;
  using const_iterator = internal::const_iterator;
  using pointer = internal::pointer;
  using const_pointer = internal::const_pointer;

  [[nodiscard]] reference operator[](Enum) noexcept;
  [[nodiscard]] const_reference operator[](Enum) const noexcept;

  [[nodiscard]] iterator begin();
  [[nodiscard]] iterator end();

  [[nodiscard]] const_iterator begin() const;
  [[nodiscard]] const_iterator end() const;

  [[nodiscard]] pointer data();
  [[nodiscard]] const_pointer data() const;

  [[nodiscard]] constexpr internal &impl() noexcept;
  [[nodiscard]] constexpr internal const &impl() const noexcept;
private:
  [[nodiscard]] static internal::size_type to_index(Enum) noexcept;

  internal impl_;
};

FCPPT_PP_POP_WARNING

}

#endif
