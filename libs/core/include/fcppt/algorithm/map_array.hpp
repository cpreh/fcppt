//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_MAP_ARRAY_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_ARRAY_HPP_INCLUDED

#include <fcppt/algorithm/map_impl_fwd.hpp>
#include <fcppt/array/is_object.hpp>
#include <fcppt/array/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
template <typename Source, typename Target>
struct map_impl<
    Source,
    Target,
    std::enable_if_t<
        std::conjunction_v<fcppt::array::is_object<Target>, fcppt::array::is_object<Source>>>>
{
  template <typename Arg, typename Function>
  static Target execute(Arg &&_arg, Function const &_function)
  {
    return fcppt::array::map(std::forward<Arg>(_arg), _function);
  }
};
}

#endif
