
//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/log/name.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/parameters_no_function.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::log::parameters fcppt::log::parameters_no_function(fcppt::log::name &&_name)
{
  return fcppt::log::parameters{std::move(_name), fcppt::log::format::optional_function{}};
}
