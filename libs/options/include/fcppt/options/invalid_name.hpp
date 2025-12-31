//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_INVALID_NAME_HPP_INCLUDED
#define FCPPT_OPTIONS_INVALID_NAME_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/invalid_name_fwd.hpp>
#include <fcppt/options/exception.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>

namespace fcppt::options
{
class FCPPT_SYMBOL_CLASS invalid_name : public fcppt::options::exception
{
public:
  FCPPT_OPTIONS_DETAIL_SYMBOL
  explicit invalid_name(fcppt::string &&);

  FCPPT_OPTIONS_DETAIL_SYMBOL
  invalid_name(invalid_name const &);

  FCPPT_OPTIONS_DETAIL_SYMBOL
  invalid_name(invalid_name &&) noexcept;

  FCPPT_OPTIONS_DETAIL_SYMBOL
  invalid_name &operator=(invalid_name const &);

  FCPPT_OPTIONS_DETAIL_SYMBOL
  invalid_name &operator=(invalid_name &&) noexcept;

  FCPPT_OPTIONS_DETAIL_SYMBOL
  ~invalid_name() noexcept override;

  [[nodiscard]]
  FCPPT_OPTIONS_DETAIL_SYMBOL
  fcppt::string const &get() const;
private:
  fcppt::string name_;
};

}

#endif
