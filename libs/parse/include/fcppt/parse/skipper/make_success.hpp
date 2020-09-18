//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SKIPPER_MAKE_SUCCESS_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_MAKE_SUCCESS_HPP_INCLUDED

#include <fcppt/either/error.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/parse/error.hpp>


namespace fcppt
{
namespace parse
{
namespace skipper
{

template<
	typename Ch
>
fcppt::either::error<
	fcppt::parse::error<
		Ch
	>
>
make_success()
{
	return
		fcppt::either::make_success<
			fcppt::parse::error<
				Ch
			>
		>(
			fcppt::either::no_error{}
		);
}

}
}
}

#endif
