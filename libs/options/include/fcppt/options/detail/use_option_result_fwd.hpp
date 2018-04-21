//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_USE_OPTION_RESULT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_USE_OPTION_RESULT_FWD_HPP_INCLUDED

#include <fcppt/optional_string_fwd.hpp>
#include <fcppt/either/object_fwd.hpp>
#include <fcppt/options/detail/missing_option_argument_fwd.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

typedef
fcppt::either::object<
	fcppt::options::detail::missing_option_argument,
	fcppt::optional_string
>
use_option_result;

}
}
}

#endif
