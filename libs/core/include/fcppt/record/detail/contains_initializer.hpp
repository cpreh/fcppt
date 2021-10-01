//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/any_of.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/detail/label_is_same.hpp>

namespace fcppt::record::detail
{
template <typename Args, typename Element>
using contains_initializer = fcppt::mpl::list::any_of<
    Args,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::record::detail::label_is_same>,
        fcppt::mpl::constant<fcppt::record::element_to_label<Element>>,
        fcppt::mpl::arg<1>>>;
}

#endif
