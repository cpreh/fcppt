//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_MAP_IMPL_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_IMPL_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/map_impl_fwd.hpp>
#include <fcppt/algorithm/detail/map_reserve.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
template <typename Source, typename Target, typename Enable>
struct map_impl
{
  template <typename Arg, typename Function>
  static Target execute(Arg &&_arg, Function const &_function)
  {
    Target result{};

    fcppt::algorithm::detail::map_reserve(result, _arg);

    fcppt::algorithm::loop(std::forward<Arg>(_arg), [&_function, &result](auto &&_map_element) {
      result.insert(
          // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
          result.end(),
          _function(fcppt::move_if_rvalue<Arg>(_map_element)));
    });

    return result;
  }
};

}

#endif
