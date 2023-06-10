//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_UNIT_USAGE_HPP_INCLUDED
#define FCPPT_OPTIONS_UNIT_USAGE_HPP_INCLUDED

#include <fcppt/options/unit_usage_fwd.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class unit_usage
{
public:
  [[nodiscard]] bool operator==(unit_usage const &) const = default;
};

}

#endif
