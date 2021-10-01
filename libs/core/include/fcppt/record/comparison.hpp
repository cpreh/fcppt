//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_COMPARISON_HPP_INCLUDED
#define FCPPT_RECORD_COMPARISON_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/record/are_equivalent.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/object_impl.hpp>

namespace fcppt::record
{
/**
\brief Compares two records for equality

\ingroup fcpptrecord

\tparam Types1 Must be equivalent to Types2
\tparam Types2 Must be equivalent to Types1
*/
template <typename... Types1, typename... Types2>
bool operator==(
    fcppt::record::object<Types1...> const &_record1,
    fcppt::record::object<Types2...> const &_record2)
{
  static_assert(
      fcppt::record::
          are_equivalent<fcppt::record::object<Types1...>, fcppt::record::object<Types2...>>::value,
      "Both records must be equivalent");

  return fcppt::algorithm::all_of(
      fcppt::record::element_vector<fcppt::record::object<Types1...>>{},
      [&_record1,
       &_record2]<typename Label, typename Type>(fcppt::tag<fcppt::record::element<Label, Type>>)
      { return fcppt::record::get<Label>(_record1) == fcppt::record::get<Label>(_record2); });
}

/**
\brief Compares two records for inequality

\ingroup fcpptrecord

\tparam Types1 Must be equivalent to Types2
\tparam Types2 Must be equivalent to Types1
*/
template <typename... Types1, typename... Types2>
inline bool operator!=(
    fcppt::record::object<Types1...> const &_record1,
    fcppt::record::object<Types2...> const &_record2)
{
  return !(_record1 == _record2);
}

}

#endif
