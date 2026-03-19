//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRING_TO_WSTRING_CONVERSION_FAILED_HPP_INCLUDED
#define FCPPT_STRING_TO_WSTRING_CONVERSION_FAILED_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>
#include <fcppt/config/external_begin.hpp>
#include <stdexcept>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
class FCPPT_SYMBOL_CLASS string_to_wstring_conversion_failed : public std::runtime_error
{
public:
  FCPPT_DECLARE_STRONG_TYPEDEF(std::string, input_type);

  FCPPT_DETAIL_SYMBOL
  explicit string_to_wstring_conversion_failed(input_type &&);

  FCPPT_DETAIL_SYMBOL
  string_to_wstring_conversion_failed(string_to_wstring_conversion_failed const &);

  FCPPT_DETAIL_SYMBOL
  string_to_wstring_conversion_failed(string_to_wstring_conversion_failed &&) noexcept;

  FCPPT_DETAIL_SYMBOL
  string_to_wstring_conversion_failed &operator=(string_to_wstring_conversion_failed const &);

  FCPPT_DETAIL_SYMBOL
  string_to_wstring_conversion_failed &operator=(string_to_wstring_conversion_failed &&) noexcept;

  FCPPT_DETAIL_SYMBOL
  ~string_to_wstring_conversion_failed() noexcept override;

  [[nodiscard]]
  FCPPT_DETAIL_SYMBOL std::string const &input() const;
private:
  std::string input_;
};

}

#endif
