//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MISSING_OPTION_ARGUMENT_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_MISSING_OPTION_ARGUMENT_ERROR_HPP_INCLUDED

#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep
#include <fcppt/options/missing_option_argument_error_fwd.hpp>
#include <fcppt/options/name.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class missing_option_argument_error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL explicit missing_option_argument_error(fcppt::options::name &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::name const &name() const;

  [[nodiscard]] bool operator==(missing_option_argument_error const &) const = default;
private:
  fcppt::options::name option_;
};

}

#endif
