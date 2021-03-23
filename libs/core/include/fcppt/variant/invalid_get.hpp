//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_INVALID_GET_HPP_INCLUDED
#define FCPPT_VARIANT_INVALID_GET_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/symbol/class.hpp>
#include <fcppt/variant/exception.hpp>
#include <fcppt/variant/invalid_get_fwd.hpp>

namespace fcppt
{
namespace variant
{
/**
\brief Thrown by #fcppt::variant::get_exn.

\ingroup fcpptvariant
*/
class FCPPT_SYMBOL_CLASS invalid_get : public fcppt::variant::exception
{
public:
  FCPPT_DETAIL_SYMBOL
  explicit invalid_get(fcppt::string &&);

  FCPPT_DETAIL_SYMBOL
  invalid_get(invalid_get const &);

  FCPPT_DETAIL_SYMBOL
  invalid_get(invalid_get &&) noexcept;

  FCPPT_DETAIL_SYMBOL
  invalid_get &operator=(invalid_get const &);

  FCPPT_DETAIL_SYMBOL
  invalid_get &operator=(invalid_get &&) noexcept;

  FCPPT_DETAIL_SYMBOL
  ~invalid_get() noexcept override;
};

}
}

#endif
