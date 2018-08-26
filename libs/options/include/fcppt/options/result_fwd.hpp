//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_RESULT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_RESULT_FWD_HPP_INCLUDED

#include <fcppt/either/object_fwd.hpp>
#include <fcppt/options/error_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The result of a parse operation.

\ingroup fcpptoptions

The result of a parse is either \a T or an \link fcppt::options::error\endlink.
*/
template<
	typename T
>
using
result
=
fcppt::either::object<
	fcppt::options::error,
	T
>;

}
}

#endif
