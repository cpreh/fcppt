//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_DECL_HPP_INCLUDED

#include <fcppt/parse/error_fwd.hpp>
#include <fcppt/parse/fatal_tag_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)

/**
\brief The error type.
\ingroup fcpptparse

An error consists of a string, containing the error message, and a bit telling if the error is fatal.
Fatal error are used by parsers such as #fcppt::parse::alternative and #fcppt::parse::repetition to stop early.
This can improve error messages and reduce backtracking time.
*/
template <typename Ch>
class error
{
public:
  using value_type = std::basic_string<Ch>;

  explicit error(value_type &&);

  error(value_type &&, fcppt::parse::fatal_tag const &);

  [[nodiscard]] bool is_fatal() const;

  [[nodiscard]] value_type &get();

  [[nodiscard]] value_type const &get() const;

private:
  value_type value_;

  bool is_fatal_;
};

FCPPT_PP_POP_WARNING

}

#endif
