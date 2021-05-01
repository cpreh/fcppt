//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_DETAIL_HAS_MAXIMUM_HPP_INCLUDED
#define FCPPT_ENUM_DETAIL_HAS_MAXIMUM_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_::detail
{

template<typename Enum, typename Enable = void>
struct has_maximum
{
  using type = std::false_type;
};

template<typename Enum>
struct has_maximum<Enum, std::enable_if_t<Enum::fcppt_maximum == Enum::fcppt_maximum>> // NOLINT(misc-redundant-expression)
{
  using type = std::true_type;
};

}

#endif
