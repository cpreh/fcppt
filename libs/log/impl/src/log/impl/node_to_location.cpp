//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/not.hpp>
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/algorithm/reverse.hpp>
#include <fcppt/container/tree/make_to_root.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/location_string_vector.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/impl/node_to_location.hpp>
#include <fcppt/optional/make_if.hpp>

fcppt::log::location
fcppt::log::impl::node_to_location(fcppt::log::detail::context_tree const &_node)
{
  return fcppt::log::location{
      fcppt::algorithm::reverse(fcppt::algorithm::map_optional<fcppt::log::location_string_vector>(
          fcppt::container::tree::make_to_root(_node),
          [](fcppt::log::detail::context_tree const &_cur)
          {
            fcppt::log::name const &name{_cur.value().name()};
            return fcppt::optional::make_if(
                fcppt::not_(name.get().empty()), fcppt::const_(name.get()));
          }))};
}
