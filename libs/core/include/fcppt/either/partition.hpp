//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_PARTITION_HPP_INCLUDED
#define FCPPT_EITHER_PARTITION_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/either/partition_result.hpp>
#include <fcppt/either/to_variant.hpp>
#include <fcppt/either/variant_type.hpp>
#include <fcppt/variant/partition.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ranges>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Partitions a container of variants into multiple containers.
\ingroup fcppteither

\tparam Source A container of #fcppt::either::object.
*/
template <typename Source>
[[nodiscard]]
fcppt::either::partition_result<Source>
partition(Source &&_source) // NOLINT(cppcoreguidelines-missing-std-forward)
{
  using source_type = std::ranges::range_value_t<Source>;

  return fcppt::variant::partition(
      fcppt::algorithm::map<std::vector<fcppt::either::variant_type<source_type>>>(
          _source,
          [](source_type &_value)
          { return fcppt::either::to_variant(fcppt::move_if_rvalue<Source>(_value)); }));
}
}

#endif
