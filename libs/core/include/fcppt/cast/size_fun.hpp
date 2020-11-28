//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_SIZE_FUN_HPP_INCLUDED
#define FCPPT_CAST_SIZE_FUN_HPP_INCLUDED

#include <fcppt/cast/size.hpp>

namespace fcppt
{
namespace cast
{
/**
\brief Function object of fcppt::cast::size

\ingroup fcpptcasts
*/
struct size_fun
{
  template <typename Dest, typename Source>
  static constexpr Dest execute(Source const &_source) noexcept
  {
    return fcppt::cast::size<Dest>(_source);
  }
};

}
}

#endif
