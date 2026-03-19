//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SYSTEM_CONVERSION_FAILED_HPP_INCLUDED
#define FCPPT_SYSTEM_CONVERSION_FAILED_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>

namespace fcppt
{
class FCPPT_SYMBOL_CLASS system_conversion_failed : public fcppt::exception
{
public:
  FCPPT_DECLARE_STRONG_TYPEDEF(fcppt::string, command_type);

  FCPPT_DETAIL_SYMBOL
  explicit system_conversion_failed(command_type &&);

  FCPPT_DETAIL_SYMBOL
  system_conversion_failed(system_conversion_failed const &);

  FCPPT_DETAIL_SYMBOL
  system_conversion_failed(system_conversion_failed &&) noexcept;

  FCPPT_DETAIL_SYMBOL
  system_conversion_failed &operator=(system_conversion_failed const &);

  FCPPT_DETAIL_SYMBOL
  system_conversion_failed &operator=(system_conversion_failed &&) noexcept;

  FCPPT_DETAIL_SYMBOL
  ~system_conversion_failed() noexcept override;

  [[nodiscard]]
  FCPPT_DETAIL_SYMBOL
  fcppt::string const &command() const;
private:
  fcppt::string command_;
};

}

#endif
