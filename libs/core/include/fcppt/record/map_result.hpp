//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_MAP_RESULT_HPP_INCLUDED
#define FCPPT_RECORD_MAP_RESULT_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/record/map_elements.hpp>
#include <fcppt/record/detail/map_result.hpp>

namespace fcppt
{
namespace record
{
/**
\brief The result of mapping a record.

\ingroup fcpptrecord
*/
template <typename Record, typename Function>
using map_result = fcppt::record::map_elements<
    Record,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::record::detail::map_result>,
        fcppt::mpl::constant<Function>,
        fcppt::mpl::arg<1>>>;

}
}

#endif
