//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_PARSE_ERROR_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_ERROR_FWD_HPP_INCLUDED

#include <fcppt/options/error_fwd.hpp>
#include <fcppt/options/missing_error_fwd.hpp>
#include <fcppt/variant/object_fwd.hpp>

namespace fcppt::options
{
/**
\brief The error type returned by parsers.

\ingroup fcpptoptions

An error can either be caused by a missing argument or option, or by something
else like a failed conversion.
*/
using parse_error = fcppt::variant::object<fcppt::options::missing_error, fcppt::options::error>;
}

#endif
