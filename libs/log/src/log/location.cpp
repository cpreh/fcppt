//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/location_string_vector.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::log::location::location() : entries_{} {}

fcppt::log::location::location(fcppt::log::name _initial) : entries_{std::move(_initial.get())} {}

fcppt::log::location::location(fcppt::log::location_string_vector &&_entries)
    : entries_{std::move(_entries)}
{
}

fcppt::log::location &fcppt::log::location::operator/=(fcppt::log::name _string)
{
  this->entries_.push_back(std::move(_string.get()));

  return *this;
}

fcppt::log::location::const_iterator fcppt::log::location::begin() const
{
  return this->entries_.begin();
}

fcppt::log::location::const_iterator fcppt::log::location::end() const
{
  return this->entries_.end();
}

fcppt::string fcppt::log::location::string() const
{
  return fcppt::algorithm::join_strings(this->entries_, FCPPT_TEXT("::"));
}

fcppt::log::location fcppt::log::operator/(fcppt::log::location _location, fcppt::log::name _string)
{
  return _location /= std::move(_string);
}
