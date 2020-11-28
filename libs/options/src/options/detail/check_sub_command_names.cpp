//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/detail/check_sub_command_names.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <unordered_map>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

void fcppt::options::detail::check_sub_command_names(std::vector<fcppt::string> const &_names)
{
  std::unordered_map<fcppt::string, std::size_t> count_map{};

  for (fcppt::string const &name : _names)
  {
    ++count_map[name];
  }

  for (std::pair<fcppt::string const, std::size_t> const &element : count_map)
  {
    if (element.second > 1U)
    {
      throw fcppt::options::duplicate_names{
          FCPPT_TEXT("Sub command name \"") + element.first +
          FCPPT_TEXT("\" specified multiple times!")};
    }
  }
}
