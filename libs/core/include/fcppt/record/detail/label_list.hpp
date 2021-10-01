//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_LABEL_LIST_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_LABEL_LIST_HPP_INCLUDED

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/record/element_to_label.hpp>

namespace fcppt::record::detail
{
template <typename ElementList>
using label_list =
    fcppt::mpl::list::map<ElementList, fcppt::mpl::lambda<fcppt::record::element_to_label>>;

}

#endif
