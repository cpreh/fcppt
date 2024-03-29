//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_ELEMENT_AT_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ELEMENT_AT_HPP_INCLUDED

#include <fcppt/mpl/list/index_of_if.hpp>
#include <fcppt/record/detail/find_element_predicate.hpp>
#include <fcppt/tuple/get.hpp>

namespace fcppt::record::detail
{
template <typename Types, typename Label, typename Tuple>
inline decltype(auto) element_at(Tuple &_elements)
{
  return fcppt::tuple::get<fcppt::mpl::list::index_of_if<
      Types,
      fcppt::record::detail::find_element_predicate<Label>>::value>(_elements);
}

}

#endif
