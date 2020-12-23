//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_TUPLE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/tuple/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Like std::tuple but with a proper constructor.
\ingroup fcppttuple
*/
template <typename... Types>
class object
{
public:
  using impl_type = std::tuple<Types...>;

  template <
      typename... Args,
      typename = std::enable_if_t<
          sizeof...(Types) == sizeof...(Args) &&
          std::conjunction_v<std::is_constructible<Types, Args>...>>>
  constexpr explicit object(Args &&...) noexcept(
      std::conjunction_v<std::is_nothrow_constructible<Types, Args>...>);

  [[nodiscard]] constexpr impl_type &impl() noexcept;

  [[nodiscard]] constexpr impl_type const &impl() const noexcept;
private:
  impl_type impl_;
};

}

#endif
