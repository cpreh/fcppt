//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_MAKE_HPP_INCLUDED
#define FCPPT_CONTAINER_MAKE_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
/**
\brief Creates a container from variadic arguments by moving.

\ingroup fcpptcontainer
*/
template <typename Container, typename... Args>
inline Container make(Args &&..._args)
{
  using reference_type = fcppt::reference<fcppt::type_traits::value_type<Container>>;

  return fcppt::algorithm::map<Container>(
      fcppt::array::object<reference_type, sizeof...(Args)>{reference_type(_args)...},
      [](reference_type const _ref) { return std::move(_ref.get()); });
}

}
}

#endif
