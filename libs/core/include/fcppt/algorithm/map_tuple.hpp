//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_MAP_TUPLE_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_TUPLE_HPP_INCLUDED

#include <fcppt/algorithm/map_impl_fwd.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
template <typename Source, typename Target>
struct map_impl<
    Source,
    Target,
    std::enable_if_t<std::conjunction_v<
        fcppt::tuple::is_object<Target>,
        fcppt::tuple::is_object<Source>>>>
{
  template <typename Arg, typename Function>
  static inline Target execute(Arg &&_arg, Function const &_function)
  {
    return fcppt::tuple::map(std::forward<Arg>(_arg), _function);
  }
};
}
}

#endif
