//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MICRO_VERSION_HPP_INCLUDED
#define FCPPT_MICRO_VERSION_HPP_INCLUDED

#include <fcppt/version.hpp>
#include <fcppt/version_integral_c.hpp>
#include <fcppt/detail/version_power.hpp>

namespace fcppt
{
/**
\brief fcppt's micro version
\ingroup fcpptvarious
*/
using micro_version =
    fcppt::version_integral_c<fcppt::version::value % fcppt::detail::version_power>;
}

#endif
