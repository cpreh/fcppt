//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_BASE_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_BASE_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/options/base_fwd.hpp> // IWYU pragma: keep
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/usage_fwd.hpp>
#include <fcppt/record/is_object.hpp>

namespace fcppt::options
{
/**
\brief The base class for parsers with a given result type.

\ingroup fcpptoptions

This class serves as a base class for a concrete parser using \a Result as its
result type. Hiding a concrete parser implementation is not necessary, but it
can reduce compile times, and it hides the concrete (permuted) result type.

\tparam Result The result type of the parser. Must be an #fcppt::record::object.
*/
template <typename Result>
class base
{
  FCPPT_NONMOVABLE(base);

  static_assert(fcppt::record::is_object<Result>::value, "Result must be an fcppt::record::object");

protected:
  base();

public:
  virtual ~base() = 0;

  using result_type = Result;

  [[nodiscard]] virtual fcppt::options::parse_result<result_type>
  parse(fcppt::options::state &&, fcppt::options::parse_context const &) const = 0;

  [[nodiscard]] virtual fcppt::options::flag_name_set flag_names() const = 0;

  [[nodiscard]] virtual fcppt::options::option_name_set option_names() const = 0;

  [[nodiscard]] virtual fcppt::options::usage usage() const = 0;
};

}

#endif
