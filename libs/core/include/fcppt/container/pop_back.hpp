//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_POP_BACK_HPP_INCLUDED
#define FCPPT_CONTAINER_POP_BACK_HPP_INCLUDED

#include <fcppt/container/to_value_type.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
/**
\brief Pops the back of a container as an optional.

\ingroup fcpptcontainer
*/
template <typename Container>
fcppt::optional::object<fcppt::container::to_value_type<Container>> pop_back(Container &_container)
{
  using value_type = fcppt::container::to_value_type<Container>;

  return fcppt::optional::make_if(!_container.empty(), [&_container] {
    value_type result{std::move(_container.back())};

    _container.pop_back();

    return result;
  });
}

}
}

#endif
