//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_UNIT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_UNIT_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/unit_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/object_fwd.hpp>

namespace fcppt
{
namespace options
{
/**
\brief A parser that succeeds when provided with no arguments.

\ingroup fcpptoptions

\tparam Label An #fcppt::record::label.
*/
template <typename Label>
class unit
{
public:
  unit();

  using element_type = fcppt::record::element<Label, fcppt::unit>;

  using result_type = fcppt::record::object<element_type>;

  [[nodiscard]] fcppt::options::parse_result<result_type>
  parse(fcppt::options::state &&, fcppt::options::parse_context const &) const;

  [[nodiscard]] fcppt::options::flag_name_set flag_names() const;

  [[nodiscard]] fcppt::options::option_name_set option_names() const;

  [[nodiscard]] fcppt::string usage() const;
};

}
}

#endif
