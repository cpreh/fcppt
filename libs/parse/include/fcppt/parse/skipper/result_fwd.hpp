//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_RESULT_FWD_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_RESULT_FWD_HPP_INCLUDED

#include <fcppt/either/error_fwd.hpp>
#include <fcppt/parse/error_fwd.hpp>

namespace fcppt
{
namespace parse
{
namespace skipper
{
/**
\brief The result type when skipping streams of \a Ch.
\ingroup fcpptparse
The result is an #fcppt::either::error of <code>fcppt::parse::error<Ch></code>.
*/
template <typename Ch>
using result = fcppt::either::error<fcppt::parse::error<Ch>>;

}
}
}

#endif
