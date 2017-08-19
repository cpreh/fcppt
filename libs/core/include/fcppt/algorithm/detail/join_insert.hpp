//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_JOIN_INSERT_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_JOIN_INSERT_HPP_INCLUDED

#include <fcppt/algorithm/detail/has_insert_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Result,
	typename Iterator
>
inline
typename
boost::disable_if<
	fcppt::algorithm::detail::has_insert_range<
		Result
	>,
	void
>::type
join_insert(
	Result &_result,
	Iterator const _begin,
	Iterator const _end
)
{
	_result.insert(
		_result.end(),
		_begin,
		_end
	);
}

template<
	typename Result,
	typename Iterator
>
inline
typename
boost::enable_if<
	fcppt::algorithm::detail::has_insert_range<
		Result
	>,
	void
>::type
join_insert(
	Result &_result,
	Iterator const _begin,
	Iterator const _end
)
{
	_result.insert(
		_begin,
		_end
	);
}

}
}
}

#endif
