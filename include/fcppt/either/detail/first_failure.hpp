//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_DETAIL_FIRST_FAILURE_HPP_INCLUDED
#define FCPPT_EITHER_DETAIL_FIRST_FAILURE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <utility>
#include <fcppt/config/external_end.hpp>


// TODO
namespace fcppt
{
namespace either
{
namespace detail
{

template<
	typename Failure
>
inline
Failure
first_failure()
{
	std::terminate();
}

template<
	typename Failure,
	typename Arg,
	typename... Args
>
inline
Failure
first_failure(
	Arg &&_arg,
	Args &&... _args
)
{
	return
		_arg.has_failure()
		?
			fcppt::move_if_rvalue<
				Arg
			>(
				_arg.get_failure_unsafe()
			)
		:
			fcppt::either::detail::first_failure<
				Failure
			>(
				std::forward<
					Args
				>(
					_args
				)...
			)
		;
}

}
}
}

#endif
