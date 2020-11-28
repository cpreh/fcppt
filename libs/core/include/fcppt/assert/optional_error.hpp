//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ASSERT_OPTIONAL_ERROR_HPP_INCLUDED
#define FCPPT_ASSERT_OPTIONAL_ERROR_HPP_INCLUDED

#include <fcppt/identity.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/optional/object_impl.hpp>

/**
\brief Asserts that an optional is not nothing or returns its contents

\ingroup fcpptassert

If \a opt is nothing, <code>std::terminate</code> is called. Otherwise, the
result of the macro is <code>opt.get_unsafe()</code>.
*/
#define FCPPT_ASSERT_OPTIONAL_ERROR(opt) \
  ([](decltype(fcppt::identity{}(opt)) _arg) \
       -> decltype(fcppt::move_if_rvalue<decltype(fcppt::identity{}(opt))>(_arg.get_unsafe())) { \
    FCPPT_ASSERT_PRE(_arg.has_value()); \
\
    return fcppt::move_if_rvalue<decltype(_arg)>(_arg.get_unsafe()); \
  }(opt))

#endif
