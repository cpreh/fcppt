//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_LEVEL_STRINGS_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STRINGS_HPP_INCLUDED

#include <fcppt/enum/names_array_fwd.hpp>
#include <fcppt/enum/names_impl_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>

namespace fcppt
{
namespace enum_
{
template <>
struct names_impl<fcppt::log::level>
{
  FCPPT_LOG_DETAIL_SYMBOL
  static fcppt::enum_::names_array<fcppt::log::level> const &get();
};

}
}

#endif
