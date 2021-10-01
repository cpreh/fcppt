//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_RANGE_DECL_HPP_INCLUDED
#define FCPPT_ENUM_RANGE_DECL_HPP_INCLUDED

#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/iterator_fwd.hpp>
#include <fcppt/enum/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief A range over a contiguous enum

\ingroup fcpptenum
*/
template <typename Enum>
class range
{
public:
  using value_type = Enum;

  using iterator = fcppt::enum_::iterator<Enum>;

  using const_iterator = iterator;

  static_assert(fcppt::enum_::is_object<Enum>::value, "Enum must be an fcppt.enum type");

  using size_type = fcppt::enum_::size_type<Enum>;

  constexpr range(size_type begin, size_type end) noexcept;

  [[nodiscard]] constexpr iterator begin() const noexcept;

  [[nodiscard]] constexpr iterator end() const noexcept;

  [[nodiscard]] constexpr size_type size() const noexcept;

private:
  size_type begin_;

  size_type end_;
};

}

#endif
