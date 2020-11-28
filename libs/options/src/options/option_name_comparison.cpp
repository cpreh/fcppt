//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/options/option_name.hpp>
#include <fcppt/options/option_name_comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

bool fcppt::options::operator==(
    fcppt::options::option_name const &_left, fcppt::options::option_name const &_right)
{
  return _left.name() == _right.name() && _left.get_is_short() == _right.get_is_short();
}

bool fcppt::options::operator<(
    fcppt::options::option_name const &_left, fcppt::options::option_name const &_right)
{
  return std::make_pair(_left.name(), _left.get_is_short()) <
         std::make_pair(_right.name(), _right.get_is_short());
}
