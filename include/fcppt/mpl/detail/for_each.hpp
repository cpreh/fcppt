//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_FOR_EACH_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_FOR_EACH_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{
namespace detail
{

template<
	typename Iterator,
	typename LastIterator,
	typename Fun
>
inline
typename
boost::enable_if<
	std::is_same<
		Iterator,
		LastIterator
	>,
	void
>::type
for_each(
	Fun const &
)
{
}

template<
	typename Iterator,
	typename LastIterator,
	typename Fun
>
inline
typename
boost::disable_if<
	std::is_same<
		Iterator,
		LastIterator
	>,
	void
>::type
for_each(
	Fun const &_func
)
{
	_func(
		fcppt::tag<
			typename
			boost::mpl::deref<
				Iterator
			>::type
		>()
	);

	fcppt::mpl::detail::for_each<
		typename
		boost::mpl::next<
			Iterator
		>::type,
		LastIterator
	>(
		_func
	);
}

}
}
}

#endif
