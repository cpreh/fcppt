//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/options/name.hpp>
#include <fcppt/options/detail/use_option_success.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::detail::use_option_success::use_option_success(
    fcppt::options::name &&_name, fcppt::string &&_value)
    : name_{std::move(_name)}, value_{std::move(_value)}
{
}

fcppt::options::name const &fcppt::options::detail::use_option_success::name() const
{
  return this->name_;
}

fcppt::string const &fcppt::options::detail::use_option_success::value() const
{
  return this->value_;
}
