//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_USAGE_HPP_INCLUDED
#define FCPPT_OPTIONS_USAGE_HPP_INCLUDED

#include <fcppt/options/usage_fwd.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{

/**
\brief The usage type of a parser.
\ingroup fcpptoptions
This shows to a user how a parser is supposed to be used.
*/
class usage
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL explicit usage(fcppt::options::usage_variant &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::usage_variant const &get() const;
private:
  fcppt::options::usage_variant impl_;
};

[[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL bool
operator==(fcppt::options::usage const &, fcppt::options::usage const &);

}

#endif
