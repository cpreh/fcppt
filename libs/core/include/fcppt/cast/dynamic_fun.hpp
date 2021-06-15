//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_DYNAMIC_FUN_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_FUN_HPP_INCLUDED

#include <fcppt/cast/dynamic.hpp>
#include <fcppt/cast/dynamic_fun_fwd.hpp>
#include <fcppt/optional/reference.hpp>

namespace fcppt
{
namespace cast
{
/**
\brief Function object that uses #fcppt::cast::dynamic

\ingroup fcpptcasts
*/
struct dynamic_fun
{
  template <typename Dest, typename Source>
  static fcppt::optional::reference<Dest> execute(Source &_source) noexcept
  {
    return fcppt::cast::dynamic<Dest>(_source);
  }
};

}
}

#endif
