//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_PARSE_CONTEXT_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_CONTEXT_HPP_INCLUDED

#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
class parse_context
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  explicit parse_context(fcppt::options::option_name_set &&);

  [[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL fcppt::options::option_name_set const &
  option_names() const;

private:
  fcppt::options::option_name_set option_names_;
};

}

#endif
