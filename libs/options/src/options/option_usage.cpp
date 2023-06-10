//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/option_usage.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/type_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::option_usage::option_usage(
    default_value_type &&_default_value,
    fcppt::options::long_name _long_name,
    fcppt::options::optional_short_name _short_name,
    fcppt::options::type_name &&_type,
    fcppt::options::optional_help_text _help_text)
    : default_value_{std::move(_default_value.get())},
      long_name_{std::move(_long_name)},
      short_name_{std::move(_short_name)},
      type_{std::move(_type)},
      help_text_{std::move(_help_text)}
{
}

fcppt::optional::object<fcppt::string> const &fcppt::options::option_usage::default_value() const
{
  return this->default_value_;
}

fcppt::options::long_name const &fcppt::options::option_usage::long_name() const
{
  return this->long_name_;
}

fcppt::options::optional_short_name const &fcppt::options::option_usage::short_name() const
{
  return this->short_name_;
}

fcppt::options::type_name const &fcppt::options::option_usage::type() const { return this->type_; }

fcppt::options::optional_help_text const &fcppt::options::option_usage::help_text() const
{
  return this->help_text_;
}
