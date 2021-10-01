//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_DISJOINT_PRODUCT_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_DISJOINT_PRODUCT_HPP_INCLUDED

#include <fcppt/mpl/list/append.hpp>
#include <fcppt/record/are_disjoint.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/from_list.hpp>

namespace fcppt::record::detail
{
template <typename RecordL, typename RecordR>
struct disjoint_product
{
  // TODO(concepts)
  static_assert(
      fcppt::record::are_disjoint<RecordL, RecordR>::value, "RecordL and RecordR must be disjoint");

  using type = fcppt::record::from_list<fcppt::mpl::list::append<
      fcppt::record::element_vector<RecordL>,
      fcppt::record::element_vector<RecordR>>>;
};

}

#endif
