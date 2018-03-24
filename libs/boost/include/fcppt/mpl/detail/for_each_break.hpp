//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_FOR_EACH_BREAK_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_FOR_EACH_BREAK_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
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
std::enable_if_t<
	std::is_same<
		Iterator,
		LastIterator
	>::value,
	void
>
for_each_break(
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
std::enable_if_t<
	!std::is_same<
		Iterator,
		LastIterator
	>::value,
	void
>
for_each_break(
	Fun const &_func
)
{
	switch(
		_func(
			fcppt::tag<
				typename
				boost::mpl::deref<
					Iterator
				>::type
			>()
		)
	)
	{
	case fcppt::loop::continue_:
		fcppt::mpl::detail::for_each_break<
			typename
			boost::mpl::next<
				Iterator
			>::type,
			LastIterator
		>(
			_func
		);
		return;
	case fcppt::loop::break_:
		return;
	}
}

}
}
}

#endif
