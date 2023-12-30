//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_MAP_ELEMENTS_HPP_INCLUDED
#define FCPPT_RECORD_MAP_ELEMENTS_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/from_list.hpp>

namespace fcppt::record
{
/**
\brief Maps the elements of a vector using a metafunction.

\ingroup fcpptrecord

\tparam Record Must be an #fcppt::record::object.

\tparam Function A metafunction accepting #fcppt::record::element
as parameter and returning the new mapped type.
*/
template <typename Record, typename Function>
using map_elements = fcppt::record::from_list<fcppt::mpl::list::map<
    fcppt::record::element_vector<Record>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::record::element>,
        fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::record::element_to_label>, fcppt::mpl::arg<1>>,
        Function>>>;
}

#endif
