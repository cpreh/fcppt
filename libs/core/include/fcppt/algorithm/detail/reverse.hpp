//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_REVERSE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_REVERSE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
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
typename
boost::disable_if<
	std::is_lvalue_reference<
		Container
	>,
	Container
>::type
reverse(
	Container &&_container
)
{
	std::reverse(
		_container.begin(),
		_container.end()
	);

	return
		_container;
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
