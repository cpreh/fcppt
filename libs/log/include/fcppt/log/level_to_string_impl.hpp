//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_LEVEL_TO_STRING_IMPL_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_TO_STRING_IMPL_HPP_INCLUDED

#include <fcppt/enum/to_string_impl_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
template <>
struct to_string_impl<fcppt::log::level>
{
  FCPPT_LOG_DETAIL_SYMBOL
  static std::string_view get(fcppt::log::level);
};

}
}

#endif
