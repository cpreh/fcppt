//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_ELEMENT_TO_LABEL_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ELEMENT_TO_LABEL_HPP_INCLUDED

#include <fcppt/record/element_fwd.hpp>

namespace fcppt
{
namespace record
{
namespace detail
{
template <typename Element>
struct element_to_label;

template <typename Label, typename Type>
struct element_to_label<fcppt::record::element<Label, Type>>
{
  using type = Label;
};

}
}
}

#endif
