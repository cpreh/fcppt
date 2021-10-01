//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_GET_EITHER_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_GET_EITHER_HPP_INCLUDED

#include <fcppt/move_if.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/has_label.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record::detail
{
template <typename Label, typename Record1, typename Record2, typename Enable = void>
struct get_either;

template <typename Label, typename Record1, typename Record2>
struct get_either<
    Label,
    Record1,
    Record2,
    std::enable_if_t<
        fcppt::record::has_label<std::remove_cvref_t<Record1>, Label>::value>>
{
  template <typename LeftRef, typename RightRef>
  static fcppt::record::label_value_type<std::remove_cvref_t<Record1>, Label>
  get(Record1 &_record1, Record2 &)
  {
    return fcppt::move_if<!LeftRef::value>(fcppt::record::get<Label>(_record1));
  }
};

template <typename Label, typename Record1, typename Record2>
struct get_either<
    Label,
    Record1,
    Record2,
    std::enable_if_t<
        fcppt::record::has_label<std::remove_cvref_t<Record2>, Label>::value>>
{
  template <typename LeftRef, typename RightRef>
  static fcppt::record::label_value_type<std::remove_cvref_t<Record2>, Label>
  get(Record1 &, Record2 &_record2)
  {
    return fcppt::move_if<!RightRef::value>(fcppt::record::get<Label>(_record2));
  }
};

}

#endif
