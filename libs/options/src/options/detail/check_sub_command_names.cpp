//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/algorithm/contains_if.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/detail/check_name.hpp>
#include <fcppt/options/detail/check_sub_command_names.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <unordered_map>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

void fcppt::options::detail::check_sub_command_names(std::vector<fcppt::string> const &_names)
{
  for(fcppt::string const &name : _names)
  {
    fcppt::options::detail::check_name(name);
  }

  using count_map_type = std::unordered_map<fcppt::string, std::size_t>;

  count_map_type const count_map{fcppt::algorithm::fold(
      _names,
      count_map_type{},
      [](fcppt::string const &_name, count_map_type &&_map)
      {
        ++_map[_name];
        return std::move(_map);
      })};

  auto const is_duplicate{
      [](count_map_type::value_type const &_value) -> bool { return _value.second > 1U; }};

  bool const have_duplicates{fcppt::algorithm::contains_if(count_map, is_duplicate)};

  if (have_duplicates)
  {
    throw fcppt::options::duplicate_names{
        fcppt::algorithm::map_optional<fcppt::options::duplicate_names::set>(
            count_map,
            [&is_duplicate](count_map_type::value_type const &_value)
            {
              return fcppt::optional::make_if(
                  is_duplicate(_value), [&_value] { return _value.first; });
            })};
  }
}
