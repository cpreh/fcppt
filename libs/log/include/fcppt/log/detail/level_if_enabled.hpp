//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED_HPP_INCLUDED

#include <fcppt/log/object.hpp> // IWYU pragma: keep

#define FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED(stream, level, output) \
  { \
    if ((stream).enabled((level))) \
      (stream).log((level), (output)); \
  }

#endif
