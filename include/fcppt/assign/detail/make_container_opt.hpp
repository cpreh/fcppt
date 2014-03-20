//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_DETAIL_MAKE_CONTAINER_OPT_HPP_INCLUDED
#define FCPPT_ASSIGN_DETAIL_MAKE_CONTAINER_OPT_HPP_INCLUDED

#include <fcppt/assign/detail/make_opt.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace assign
{
namespace detail
{

template<
	typename Result,
	typename... Args
>
inline
Result
make_container_opt(
	Result &&_result
)
{
	return
		std::move(
			_result
		);
}

template<
	typename Result,
	typename Arg1,
	typename... Args
>
inline
Result
make_container_opt(
	Result &&_result,
	Arg1 &&_arg1,
	Args && ..._args
)
{
	return
		fcppt::assign::detail::make_container_opt(
			fcppt::assign::detail::make_opt(
				std::move(
					_result
				),
				std::forward<
					Arg1
				>(
					_arg1
				)
			),
			std::forward<
				Args
			>(
				_args
			)...
		);
}

}
}
}

#endif
