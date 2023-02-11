//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_DECL_HPP_INCLUDED

#include <fcppt/parse/error_fwd.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/comparison.hpp>

namespace fcppt::parse
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)

/**
\brief The error type.
\ingroup fcpptparse

An error consists of an #fcppt::parse::error_variant and a bit telling if the error is fatal.
Fatal error are used by parsers such as #fcppt::parse::alternative and #fcppt::parse::repetition to stop early.
This can improve error messages and reduce backtracking time.
*/
template <typename Ch>
class error
{
public:
  using variant_type = fcppt::parse::error_variant<Ch>;

  error(variant_type &&, fcppt::parse::is_fatal);

  [[nodiscard]] bool is_fatal() const;

  [[nodiscard]] variant_type &get();

  [[nodiscard]] variant_type const &get() const;

  [[nodiscard]] bool operator==(error const &) const = default;
private:
  variant_type value_;

  bool is_fatal_;
};

FCPPT_PP_POP_WARNING

}

#endif
