//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_DETAIL_ALL_SUCCESS_HPP_INCLUDED
#define FCPPT_EITHER_DETAIL_ALL_SUCCESS_HPP_INCLUDED


namespace fcppt
{
namespace either
{
namespace detail
{

// TODO
inline
bool
all_success()
{
	return
		true;
}

template<
	typename Arg,
	typename... Args
>
inline
bool
all_success(
	Arg const &_arg,
	Args const &... _args
)
{
	return
		_arg.has_success()
		&&
		fcppt::either::detail::all_success(
			_args...
		);
}

}
}
}

#endif
