//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_MOVE_IF_RVALUE_HPP_INCLUDED
#define FCPPT_DETAIL_MOVE_IF_RVALUE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Type,
	typename Arg
>
inline
typename
boost::enable_if<
	std::is_reference<
		Type
	>,
	Arg &
>::type
move_if_rvalue(
	Arg &_arg
)
{
	return
		_arg;
}

template<
	typename Type,
	typename Arg
>
inline
typename
boost::disable_if<
	std::is_reference<
		Type
	>,
	Arg &&
>::type
move_if_rvalue(
	Arg &_arg
)
{
	return
		std::move(
			_arg
		);
}

}
}

#endif
