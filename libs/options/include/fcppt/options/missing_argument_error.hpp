//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MISSING_ARGUMENT_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_MISSING_ARGUMENT_ERROR_HPP_INCLUDED

#include <fcppt/options/missing_argument_error_fwd.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class missing_argument_error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL explicit missing_argument_error(fcppt::options::long_name);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::long_name const &long_name() const;

  [[nodiscard]] bool operator==(missing_argument_error const &) const = default;
private:
  fcppt::options::long_name long_name_;
};

}

#endif
