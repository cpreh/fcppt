//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/options/exception.hpp>
#include <fcppt/options/invalid_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::invalid_name::invalid_name(fcppt::string &&_name)
    : fcppt::options::
          exception{fcppt::string{FCPPT_TEXT("The name \"")} + _name + FCPPT_TEXT("\" is invalid. It cannot start with a -.")},
      name_{std::move(_name)}
{
}

fcppt::options::invalid_name::invalid_name(invalid_name const &) = default;

fcppt::options::invalid_name::invalid_name(invalid_name &&) noexcept = default;

fcppt::options::invalid_name &
fcppt::options::invalid_name::operator=(invalid_name const &) = default;

fcppt::options::invalid_name &
fcppt::options::invalid_name::operator=(invalid_name &&) noexcept = default;

fcppt::options::invalid_name::~invalid_name() noexcept = default;

fcppt::string const &fcppt::options::invalid_name::get() const
{
  return this->name_;
}
