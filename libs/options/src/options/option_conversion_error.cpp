//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/options/name.hpp>
#include <fcppt/options/option_conversion_error.hpp>
#include <fcppt/options/type_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::option_conversion_error::option_conversion_error(
    fcppt::string _arg, fcppt::options::type_name &&_type_name, fcppt::options::name &&_name)
    : arg_{std::move(_arg)}, type_name_{std::move(_type_name)}, name_{std::move(_name)}
{
}

fcppt::string const &fcppt::options::option_conversion_error::arg() const
{
  return this->arg_;
}

fcppt::options::type_name const &fcppt::options::option_conversion_error::type_name() const
{
  return this->type_name_;
}

fcppt::options::name const &fcppt::options::option_conversion_error::name() const
{
  return this->name_;
}
