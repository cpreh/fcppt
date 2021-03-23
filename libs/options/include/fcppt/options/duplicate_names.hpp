//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DUPLICATE_NAMES_HPP_INCLUDED
#define FCPPT_OPTIONS_DUPLICATE_NAMES_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/duplicate_names_fwd.hpp>
#include <fcppt/options/exception.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>

namespace fcppt
{
namespace options
{
class FCPPT_SYMBOL_CLASS duplicate_names : public fcppt::options::exception
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  explicit duplicate_names(fcppt::string &&);

  FCPPT_OPTIONS_DETAIL_SYMBOL
  duplicate_names(duplicate_names const &);

  FCPPT_OPTIONS_DETAIL_SYMBOL
  duplicate_names(duplicate_names &&) noexcept;

  FCPPT_OPTIONS_DETAIL_SYMBOL
  duplicate_names &operator=(duplicate_names const &);

  FCPPT_OPTIONS_DETAIL_SYMBOL
  duplicate_names &operator=(duplicate_names &&) noexcept;

  FCPPT_OPTIONS_DETAIL_SYMBOL
  ~duplicate_names() noexcept override;
};

}
}

#endif
