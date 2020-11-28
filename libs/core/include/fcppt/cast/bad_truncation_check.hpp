//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_BAD_TRUNCATION_CHECK_HPP_INCLUDED
#define FCPPT_CAST_BAD_TRUNCATION_CHECK_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/cast/bad_truncation_check_fwd.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeindex>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace cast
{
/**
\brief May be thrown by #fcppt::cast::truncation_check  if the
conversion truncates

\ingroup fcpptcasts

This class provides type information about the source and the destination
types, stored as std::type_index.

\see fcppt::truncation_check_cast
*/
class FCPPT_SYMBOL_CLASS bad_truncation_check : public fcppt::exception
{
public:
  /**
  \brief Constructs a bad_truncation_check_cast exception

  \param source_value The value to cast from

  \param source The source type information

  \param dest The destination type information
  */
  FCPPT_DETAIL_SYMBOL
  bad_truncation_check(
      fcppt::string &&source_value, std::type_index const &source, std::type_index const &dest);

  FCPPT_DETAIL_SYMBOL
  bad_truncation_check(bad_truncation_check const &);

  FCPPT_DETAIL_SYMBOL
  bad_truncation_check(bad_truncation_check &&) noexcept;

  FCPPT_DETAIL_SYMBOL
  bad_truncation_check &operator=(bad_truncation_check const &);

  FCPPT_DETAIL_SYMBOL
  bad_truncation_check &operator=(bad_truncation_check &&) noexcept;

  FCPPT_DETAIL_SYMBOL
  ~bad_truncation_check() noexcept override;

  /**
  \brief Returns the source type information
  */
  [[nodiscard]] FCPPT_DETAIL_SYMBOL std::type_index const &source() const;

  /**
  \brief Returns the destination type information
  */
  [[nodiscard]] FCPPT_DETAIL_SYMBOL std::type_index const &destination() const;

private:
  std::type_index source_, destination_;
};

}
}

#endif
