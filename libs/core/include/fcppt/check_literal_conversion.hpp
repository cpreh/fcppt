//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CHECK_LITERAL_CONVERSION_HPP_INCLUDED
#define FCPPT_CHECK_LITERAL_CONVERSION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

/**
\brief Checks if a literal conversion is safe

\ingroup fcpptvarious

\a source must not be a <code>bool</code> or if \a dest is integral, then \a
source must not be floating-point.
*/
#define FCPPT_CHECK_LITERAL_CONVERSION(dest, source) \
  static_assert( \
      !std::is_same_v<source, bool> && \
          !(std::is_integral_v<dest> && std::is_floating_point_v<source>), \
      "A literal conversion from bool, or from floating point to int is not allowed!")

#endif
