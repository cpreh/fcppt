//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_UNCONS_HPP_INCLUDED
#define FCPPT_CONTAINER_UNCONS_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/not.hpp>
#include <fcppt/container/uncons_result.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <ranges>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container
{
/**
\brief Splits a container into its head and tail.

\ingroup fcpptcontainer
*/
template <typename Container>
[[nodiscard]] fcppt::container::uncons_result<Container> uncons(Container &_container)
{
  return fcppt::optional::make_if(
      fcppt::not_(_container.empty()),
      [&_container]
      {
        return fcppt::tuple::make(
            fcppt::make_ref(*_container.begin()),
            std::ranges::subrange{std::next(_container.begin()), _container.end()});
      });
}
}

#endif
