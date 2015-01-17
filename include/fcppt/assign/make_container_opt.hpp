//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_MAKE_CONTAINER_OPT_HPP_INCLUDED
#define FCPPT_ASSIGN_MAKE_CONTAINER_OPT_HPP_INCLUDED

#include <fcppt/assign/detail/make_container_opt.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace assign
{

/**
\brief Creates a container from arguments which can be optional

\ingroup fcpptassign

Creates a container of type \a Result, inserting every member from \a _args
that is not an <code>optional<Result::value_type></code>.
*/
template<
	typename Result,
	typename... Args
>
Result
make_container_opt(
	Args && ..._args
)
{
	return
		fcppt::assign::detail::make_container_opt(
			Result(),
			std::forward<
				Args
			>(
				_args
			)...
		);
}

}
}

#endif
