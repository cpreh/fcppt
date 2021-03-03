//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_RESULT_FWD_HPP_INCLUDED
#define FCPPT_PARSE_RESULT_FWD_HPP_INCLUDED

#include <fcppt/either/object_fwd.hpp>
#include <fcppt/parse/error_fwd.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief The result type when parsing streams of \a Ch, producing values of \a Type.
\ingroup fcpptparse
The result is an #fcppt::either::object of <code>fcppt::parse::error<Ch></code> and <code>Type</code>.
*/
template <typename Ch, typename Type>
using result = fcppt::either::object<fcppt::parse::error<Ch>, Type>;

}
}

#endif
