//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_FIND_ELEMENT_PREDICATE_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_FIND_ELEMENT_PREDICATE_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace record
{
namespace detail
{
template <typename Label>
using find_element_predicate = fcppt::mpl::bind<
    fcppt::mpl::lambda<std::is_same>,
    fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::record::element_to_label>, fcppt::mpl::arg<1>>,
    fcppt::mpl::constant<Label>>;
}
}
}

#endif
