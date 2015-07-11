//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_SOURCE_SIZE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_SOURCE_SIZE_HPP_INCLUDED

#include <fcppt/algorithm/detail/has_random_access_iterator.hpp>
#include <fcppt/algorithm/detail/has_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Source
>
inline
typename
boost::enable_if<
	boost::mpl::and_<
		fcppt::algorithm::detail::has_random_access_iterator<
			Source
		>,
		boost::mpl::not_<
			fcppt::algorithm::detail::has_size<
				Source
			>
		>
	>,
	typename
	std::iterator_traits<
		typename
		Source::iterator
	>::difference_type
>::type
source_size(
	Source const &_source
)
{
	return
		_source.end()
		-
		_source.begin();
}

template<
	typename Source
>
inline
typename
boost::enable_if<
	fcppt::algorithm::detail::has_size<
		Source
	>,
	typename
	Source::size_type
>::type
source_size(
	Source const &_source
)
{
	return
		_source.size();
}

}
}
}

#endif
