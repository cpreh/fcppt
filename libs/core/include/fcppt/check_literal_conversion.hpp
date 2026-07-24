//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CHECK_LITERAL_CONVERSION_HPP_INCLUDED
#define FCPPT_CHECK_LITERAL_CONVERSION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits> // IWYU pragma: keep
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

/**
\brief Checks if a literal conversion is safe

\ingroup fcpptvarious

\a source must not be a <code>bool</code> or if \a dest is integral, then \a
source must not be floating-point.
*/
template <typename Dest, typename Source>
concept check_literal_conversion = !std::is_same_v<Source, bool> &&
                                   !(std::is_integral_v<Dest> && std::is_floating_point_v<Source>);
}

#endif
