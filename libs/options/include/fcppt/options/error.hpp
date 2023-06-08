//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_ERROR_HPP_INCLUDED

#include <fcppt/options/error_fwd.hpp>
#include <fcppt/options/error_variant.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
/**
\brief The error type retuned.

\ingroup fcpptoptions
*/
class error
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL explicit error(fcppt::options::error_variant &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::error_variant const &get() const;
private:
  fcppt::options::error_variant impl_;
};

[[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL bool
operator==(fcppt::options::error const &, fcppt::options::error const &);

}

#endif
