//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_NAMES_ARRAY_FWD_HPP_INCLUDED
#define FCPPT_ENUM_NAMES_ARRAY_FWD_HPP_INCLUDED

#include <fcppt/enum/array_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief Array type for The names of an enum.

\ingroup fcpptenum

\tparam Enum Must be an enum type.
*/
template <typename Enum>
using names_array = fcppt::enum_::array<Enum, std::string_view>;

}
}

#endif
