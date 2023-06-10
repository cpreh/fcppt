//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_USAGE_VARIANT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_USAGE_VARIANT_FWD_HPP_INCLUDED

#include <fcppt/options/argument_usage_fwd.hpp>
#include <fcppt/options/commands_usage_fwd.hpp>
#include <fcppt/options/flag_usage_fwd.hpp>
#include <fcppt/options/many_usage_fwd.hpp>
#include <fcppt/options/option_usage_fwd.hpp>
#include <fcppt/options/optional_usage_fwd.hpp>
#include <fcppt/options/product_usage_fwd.hpp>
#include <fcppt/options/sum_usage_fwd.hpp>
#include <fcppt/options/unit_usage_fwd.hpp>
#include <fcppt/variant/object_fwd.hpp>

namespace fcppt::options
{

using usage_variant = fcppt::variant::object<
    fcppt::options::argument_usage,
    fcppt::options::commands_usage,
    fcppt::options::flag_usage,
    fcppt::options::many_usage,
    fcppt::options::option_usage,
    fcppt::options::optional_usage,
    fcppt::options::product_usage,
    fcppt::options::sum_usage,
    fcppt::options::unit_usage>;
}

#endif
