//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MANY_USAGE_HPP_INCLUDED
#define FCPPT_OPTIONS_MANY_USAGE_HPP_INCLUDED

#include <fcppt/recursive.hpp>
#include <fcppt/recursive_comparison.hpp> // IWYU pragma: keep
#include <fcppt/options/many_usage_fwd.hpp> // IWYU pragma: keep
#include <fcppt/options/usage_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class many_usage
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL explicit many_usage(fcppt::options::usage &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::usage const &
  inner() const;

  [[nodiscard]] bool operator==(many_usage const &) const = default;
private:
  fcppt::recursive<fcppt::options::usage> inner_;
};

}

#endif
