//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string_view.hpp>
#include <fcppt/options/is_short.hpp>
#include <fcppt/options/option_name.hpp>
#include <fcppt/options/impl/option_name_view.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

std::pair<fcppt::options::is_short, fcppt::string_view>
fcppt::options::impl::option_name_view(fcppt::options::option_name const &_value)
{
  return std::make_pair(_value.is_short(), fcppt::string_view{_value.name()});
}
