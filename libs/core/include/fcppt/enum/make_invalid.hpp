//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_MAKE_INVALID_HPP_INCLUDED
#define FCPPT_ENUM_MAKE_INVALID_HPP_INCLUDED

#include <fcppt/enum/invalid_impl.hpp>

namespace fcppt::enum_
{

/**
\ingroup fcpptenum
*/
template <typename Enum>
[[nodiscard]] inline fcppt::enum_::invalid<Enum> make_invalid(Enum const _enum)
{
  return fcppt::enum_::invalid<Enum>{_enum};
}
}

#endif
