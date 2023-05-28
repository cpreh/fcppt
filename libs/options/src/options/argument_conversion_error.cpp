//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/options/argument_conversion_error.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/type_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::argument_conversion_error::argument_conversion_error(
    fcppt::string _arg,
    fcppt::options::type_name &&_type_name,
    fcppt::options::long_name _long_name)
    : arg_{std::move(_arg)}, type_name_{std::move(_type_name)}, long_name_{std::move(_long_name)}
{
}

fcppt::string const &fcppt::options::argument_conversion_error::arg() const { return this->arg_; }

fcppt::options::type_name const &fcppt::options::argument_conversion_error::type_name() const
{
  return this->type_name_;
}

fcppt::options::long_name const &fcppt::options::argument_conversion_error::long_name() const
{
  return this->long_name_;
}
