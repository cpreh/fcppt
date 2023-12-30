//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ELEMENT_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_HPP_INCLUDED

#include <fcppt/record/element_fwd.hpp> // IWYU pragma: keep
#include <fcppt/record/is_label.hpp>

namespace fcppt::record
{
/**
\brief An element of a record

A record is declared using an MPL sequence of <em>element</em> types.

\ingroup fcpptrecord

\tparam Label Must be an #fcppt::record::label.

\tparam Type The value type of the label.
*/
template <typename Label, typename Type>
struct element
{
  using wrapped = Type;

  using label = Label;

  static_assert(
      fcppt::record::is_label<label>::value,
      "Label of element<> must be an fcppt::record::label<>");
};

}

#endif
