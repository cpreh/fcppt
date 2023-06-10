//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/options/argument_usage.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/type_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::argument_usage::argument_usage(
    fcppt::options::long_name _long_name,
    fcppt::options::type_name &&_type,
    fcppt::options::optional_help_text _help_text)
    : long_name_{std::move(_long_name)}, type_{std::move(_type)}, help_text_{std::move(_help_text)}
{
}

fcppt::options::long_name const &fcppt::options::argument_usage::long_name() const
{
  return this->long_name_;
}

fcppt::options::type_name const &fcppt::options::argument_usage::type() const
{
  return this->type_;
}

fcppt::options::optional_help_text const &fcppt::options::argument_usage::help_text() const
{
  return this->help_text_;
}
