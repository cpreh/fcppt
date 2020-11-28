//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_MAP_ARRAY_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_ARRAY_HPP_INCLUDED

#include <fcppt/algorithm/map_impl_fwd.hpp>
#include <fcppt/container/array/map.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
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
    std::enable_if_t<
        fcppt::type_traits::is_std_array<Target>::value &&
        fcppt::type_traits::is_std_array<Source>::value>>
{
  template <typename Arg, typename Function>
  static inline Target execute(Arg &&_arg, Function const &_function)
  {
    return fcppt::container::array::map(std::forward<Arg>(_arg), _function);
  }
};

}
}

#endif
