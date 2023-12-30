//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_PARAMETERS_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_HPP_INCLUDED

#include <fcppt/log/name.hpp>
#include <fcppt/log/parameters_fwd.hpp> // IWYU pragma: keep
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/format/optional_function.hpp>

namespace fcppt::log
{
/**
\brief The parameters class for an #fcppt::log::object

\ingroup fcpptlog
*/
class parameters
{
public:
  FCPPT_LOG_DETAIL_SYMBOL
  parameters(fcppt::log::name, fcppt::log::format::optional_function &&);

  [[nodiscard]] fcppt::log::name const &name() const;

  [[nodiscard]] fcppt::log::format::optional_function const &formatter() const;

private:
  fcppt::log::name name_;

  fcppt::log::format::optional_function formatter_;
};

}

#endif
