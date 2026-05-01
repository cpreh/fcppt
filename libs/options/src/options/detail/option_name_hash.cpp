//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/hash.hpp>
#include <fcppt/hash_combine.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/strong_typedef_std_hash.hpp> // IWYU pragma: keep
#include <fcppt/options/is_short.hpp>
#include <fcppt/options/option_name.hpp>
#include <fcppt/options/detail/option_name_hash.hpp>
#include <fcppt/options/impl/option_name_view.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <utility>
#include <fcppt/config/external_end.hpp>

std::size_t fcppt::options::detail::option_name_hash::operator()(fcppt::options::option_name const &_value)
{
  return fcppt::options::detail::option_name_hash::operator()(
      fcppt::options::impl::option_name_view(_value));
}

std::size_t fcppt::options::detail::option_name_hash::operator()(
    std::pair<fcppt::options::is_short, fcppt::string_view> const &_value)
{
  return fcppt::hash_combine(fcppt::hash(_value.first),fcppt::hash(_value.second));
}
