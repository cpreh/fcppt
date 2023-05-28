//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MISSING_ERROR_VARIANT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_MISSING_ERROR_VARIANT_FWD_HPP_INCLUDED

#include <fcppt/options/missing_argument_error_fwd.hpp>
#include <fcppt/options/missing_command_error_fwd.hpp>
#include <fcppt/options/missing_error_pair_fwd.hpp>
#include <fcppt/options/missing_flag_error_fwd.hpp>
#include <fcppt/options/missing_option_error_fwd.hpp>
#include <fcppt/variant/object_fwd.hpp>

namespace fcppt::options
{
using missing_error_variant = fcppt::variant::object<
    fcppt::options::missing_argument_error,
    fcppt::options::missing_command_error,
    fcppt::options::missing_error_pair,
    fcppt::options::missing_flag_error,
    fcppt::options::missing_option_error>;
}

#endif
