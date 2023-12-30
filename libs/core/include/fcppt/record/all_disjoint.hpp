//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ALL_DISJOINT_HPP_INCLUDED
#define FCPPT_RECORD_ALL_DISJOINT_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/list/join.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/mpl/set/object_fwd.hpp>
#include <fcppt/mpl/set/size.hpp>
#include <fcppt/mpl/set/to_list.hpp>
#include <fcppt/mpl/set/union.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record
{
/**
\brief Tests if multiple records have disjoint label sets.
\ingroup fcpptrecord
*/
template <fcppt::mpl::list::object_concept Records>
using all_disjoint = std::is_same<
    fcppt::mpl::set::size<fcppt::mpl::list::fold<
        Records,
        fcppt::mpl::bind<
            fcppt::mpl::lambda<fcppt::mpl::set::union_>,
            fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::record::label_set>, fcppt::mpl::arg<1>>,
            fcppt::mpl::arg<2>>,
        fcppt::mpl::set::object<>>>,
    fcppt::mpl::list::size<fcppt::mpl::list::join<fcppt::mpl::list::map<
        Records,
        fcppt::mpl::bind<
            fcppt::mpl::lambda<fcppt::mpl::set::to_list>,
            fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::record::label_set>, fcppt::mpl::arg<1>>>>>>>;
}

#endif
