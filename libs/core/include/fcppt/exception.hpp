//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EXCEPTION_HPP_INCLUDED
#define FCPPT_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception_fwd.hpp>
#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief The base class for all exceptions.

\ingroup fcpptstring

fcppt::exception is a wrapper around an exception that uses #fcppt::string
to store the error message. Note that you will have to use #fcppt::exception::string to obtain the
string. If you use <code>what()</code>, which is only provided for compatibility with
<code>std::exception</code>, nothing useful will be returned. The reason behind
this is that a string conversion itself can result in exceptions being thrown.
That is why <code>what()</code> does not try to convert from #fcppt::string to
<code>std::string</code>.
*/
class FCPPT_SYMBOL_CLASS exception : public std::exception
{
public:
  /**
  \brief Constructs an exception from a string
  */
  FCPPT_DETAIL_SYMBOL
  explicit exception(fcppt::string &&what);

  FCPPT_DETAIL_SYMBOL
  exception(exception const &);

  FCPPT_DETAIL_SYMBOL
  exception(exception &&) noexcept;

  FCPPT_DETAIL_SYMBOL
  exception &operator=(exception const &);

  FCPPT_DETAIL_SYMBOL
  exception &operator=(exception &&) noexcept;

  /**
  \brief Returns the error message

  Use this function to print the error message instead of
  <code>what()</code>
  */
  [[nodiscard]] fcppt::string const &string() const;

  /**
  \brief Returns a generic error

  This function's purpose is to provide compatibility with
  <code>std::exception</code>. It returns nothing useful.
  */
  [[nodiscard]] FCPPT_DETAIL_SYMBOL char const *what() const noexcept override;

  FCPPT_DETAIL_SYMBOL
  ~exception() noexcept override;

private:
  fcppt::string string_;
};

}

#endif
