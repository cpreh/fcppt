//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_PERMUTE_HPP_INCLUDED
#define FCPPT_RECORD_PERMUTE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/record/are_equivalent.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/record/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record
{
/**
\brief Permutes one record into another

\ingroup fcpptrecord

\tparam Result Must be equivalent to Arg, and must be an #fcppt::record::object.
\tparam Arg Must be equivalent to Result, and must be an #fcppt::record::object.
*/
template <typename Result, typename Arg>
inline Result permute(Arg &&_arg) // NOLINT(cppcoreguidelines-missing-std-forward)
{
  static_assert(fcppt::record::is_object<Result>::value, "Result must be an fcppt::record::object");

  using arg_type = std::remove_cvref_t<Arg>;

  static_assert(fcppt::record::is_object<arg_type>::value, "Arg must be an fcppt::record::object");

  static_assert(
      fcppt::record::are_equivalent<Result, arg_type>::value, "Result and Arg must be equivalent");

  return fcppt::record::init<Result>(
      [&_arg]<typename Label, typename Type>(fcppt::record::element<Label, Type>)
      { return fcppt::move_if_rvalue<Arg>(fcppt::record::get<Label>(_arg)); });
}

}

#endif
