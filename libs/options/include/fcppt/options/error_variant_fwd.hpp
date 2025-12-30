//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_ERROR_VARIANT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_ERROR_VARIANT_FWD_HPP_INCLUDED

#include <fcppt/options/argument_conversion_error_fwd.hpp>
#include <fcppt/options/dual_flag_error_fwd.hpp>
#include <fcppt/options/dual_option_error_fwd.hpp>
#include <fcppt/options/error_product_fwd.hpp>
#include <fcppt/options/error_sum_fwd.hpp>
#include <fcppt/options/invalid_command_error_fwd.hpp>
#include <fcppt/options/leftover_error_fwd.hpp>
#include <fcppt/options/missing_argument_error_fwd.hpp>
#include <fcppt/options/missing_command_error_fwd.hpp>
#include <fcppt/options/missing_flag_error_fwd.hpp>
#include <fcppt/options/missing_option_argument_error_fwd.hpp>
#include <fcppt/options/missing_option_error_fwd.hpp>
#include <fcppt/options/option_conversion_error_fwd.hpp>
#include <fcppt/variant/object_fwd.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
using error_variant = fcppt::variant::object<
    fcppt::options::argument_conversion_error,
    fcppt::options::dual_flag_error,
    fcppt::options::dual_option_error,
    fcppt::options::error_product,
    fcppt::options::error_sum,
    fcppt::options::leftover_error,
    fcppt::options::invalid_command_error,
    fcppt::options::missing_argument_error,
    fcppt::options::missing_command_error,
    fcppt::options::missing_flag_error,
    fcppt::options::missing_option_argument_error,
    fcppt::options::missing_option_error,
    fcppt::options::option_conversion_error>;
}

#endif
