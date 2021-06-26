//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_MAXIMUM_HPP_INCLUDED
#define FCPPT_MPL_LIST_MAXIMUM_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/if.hpp>
#include <fcppt/mpl/greater.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/list/front.hpp>

namespace fcppt::mpl::list
{
/**
\brief Calculates the maximum value in a sequence.

\ingroup fcpptmetal

\tparam Sequence A non empty mpl::list::object of std::integral_constants.
TODO(concepts)
*/
template <typename Sequence>
using maximum = fcppt::mpl::list::fold<
    Sequence,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::if_>,
        fcppt::mpl::
            bind<fcppt::mpl::lambda<fcppt::mpl::greater>, fcppt::mpl::arg<1>, fcppt::mpl::arg<2>>,
        fcppt::mpl::arg<1>,
        fcppt::mpl::arg<2>>,
    fcppt::mpl::list::front<Sequence>>;
}

#endif
