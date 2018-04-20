//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_REVERSE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_REVERSE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Container
>
inline
std::enable_if_t<
	!std::is_lvalue_reference<
		Container
	>::value,
	Container
>
reverse(
	Container &&_container
)
{
	std::reverse(
		_container.begin(),
		_container.end()
	);

	return
		std::move(
			_container
		);
}

template<
	typename Container
>
inline
Container
reverse(
	Container const &_container
)
{
	return
		fcppt::algorithm::detail::reverse(
			Container(
				_container
			)
		);
}

}
}
}

#endif
