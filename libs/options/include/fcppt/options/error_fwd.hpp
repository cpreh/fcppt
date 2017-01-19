//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_ERROR_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_ERROR_FWD_HPP_INCLUDED

#include <fcppt/options/missing_error_fwd.hpp>
#include <fcppt/options/other_error_fwd.hpp>
#include <fcppt/variant/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

typedef
fcppt::variant::variadic<
	fcppt::options::missing_error,
	fcppt::options::other_error
>
error;

}
}

#endif
