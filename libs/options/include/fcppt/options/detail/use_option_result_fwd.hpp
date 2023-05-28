//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_USE_OPTION_RESULT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_USE_OPTION_RESULT_FWD_HPP_INCLUDED

#include <fcppt/either/object_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/options/missing_option_argument_error_fwd.hpp>
#include <fcppt/options/detail/use_option_success_fwd.hpp>

namespace fcppt::options::detail
{
using use_option_result = fcppt::either::object<
    fcppt::options::missing_option_argument_error,
    fcppt::optional::object<fcppt::options::detail::use_option_success>>;
}

#endif
