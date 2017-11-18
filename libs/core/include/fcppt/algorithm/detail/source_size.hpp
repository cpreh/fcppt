//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_SOURCE_SIZE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_SOURCE_SIZE_HPP_INCLUDED

#include <fcppt/algorithm/detail/has_random_access_iterator.hpp>
#include <fcppt/algorithm/detail/has_size.hpp>
#include <fcppt/algorithm/detail/mpl_size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/size.hpp>
#include <iterator>
#include <type_traits>
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
std::enable_if<
	boost::mpl::and_<
		fcppt::algorithm::detail::has_random_access_iterator<
			Source
		>,
		boost::mpl::not_<
			fcppt::algorithm::detail::has_size<
				Source
			>
		>
	>::value,
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
std::enable_if<
	fcppt::algorithm::detail::has_size<
		Source
	>::value,
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

template<
	typename Source
>
inline
typename
std::enable_if<
	boost::mpl::is_sequence<
		Source
	>::value,
	typename
	fcppt::algorithm::detail::mpl_size_type<
		Source
	>::type
>::type
source_size(
	Source const &
)
{
	return
		boost::mpl::size<
			Source
		>::value;
}

}
}
}

#endif
