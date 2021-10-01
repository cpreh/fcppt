//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ELEMENT_MAP_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_MAP_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/map/insert.hpp>
#include <fcppt/mpl/map/object_fwd.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/element_vector.hpp>

namespace fcppt::record
{
/**
\brief A metafunction computing the element map of a record.

\ingroup fcpptrecord

\tparam Record Must be an #fcppt::record::object.
*/
template <typename Record>
using element_map = fcppt::mpl::list::fold<
    fcppt::record::element_vector<Record>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::map::insert>,
        fcppt::mpl::arg<2>,
        fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::record::element_to_label>, fcppt::mpl::arg<1>>,
        fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::record::element_to_type>, fcppt::mpl::arg<1>>>,
    fcppt::mpl::map::object<>>;

}

#endif
