//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_ERROR_FWD_HPP_INCLUDED
#define FCPPT_EITHER_ERROR_FWD_HPP_INCLUDED

#include <fcppt/either/no_error_fwd.hpp>
#include <fcppt/either/object_fwd.hpp>

namespace fcppt
{
namespace either
{
/**
\brief An either without a success value.

\ingroup fcppteither

An either with a failure but no success value. This is useful in case errors
are returned as optionals.
*/
template <typename Failure>
using error = fcppt::either::object<Failure, fcppt::either::no_error>;

}
}

#endif
