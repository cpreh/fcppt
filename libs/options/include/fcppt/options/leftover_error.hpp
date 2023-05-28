//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_LEFTOVER_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_LEFTOVER_ERROR_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/options/leftover_error_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\ingroup fcpptoptions
*/
class leftover_error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL explicit leftover_error(fcppt::args_vector &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::args_vector const &args() const;

  [[nodiscard]] bool operator==(leftover_error const &) const = default;
private:
  fcppt::args_vector args_;
};
}

#endif
