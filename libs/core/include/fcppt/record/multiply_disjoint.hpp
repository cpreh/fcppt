//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_MULTIPLY_DISJOINT_HPP_INCLUDED
#define FCPPT_RECORD_MULTIPLY_DISJOINT_HPP_INCLUDED

#include <fcppt/record/disjoint_product.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/record/detail/get_either.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record
{
/**
\brief Creates the disjoint product of two records

\ingroup fcpptrecord

\tparam Record1 Must be an #fcppt::record::object that is disjoint from \a Record2.
\tparam Record2 Must be an #fcppt::record::object that is disjoint from \a Record1.
*/
template <typename Record1, typename Record2>
fcppt::record::disjoint_product<
    std::remove_cvref_t<Record1>,
    std::remove_cvref_t<Record2>>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
multiply_disjoint(Record1 &&_record1, Record2 &&_record2)
{
  using result_type =
      fcppt::record::disjoint_product<std::remove_cvref_t<Record1>, std::remove_cvref_t<Record2>>;

  return fcppt::record::init<result_type>(
      [&_record1, &_record2]<typename Label, typename Type>(fcppt::record::element<Label, Type>)
      {
        return fcppt::record::detail::get_either<Label, Record1, Record2>::
            template get<std::is_lvalue_reference<Record1>, std::is_lvalue_reference<Record2>>(
                _record1, _record2);
      });
}

}

#endif
