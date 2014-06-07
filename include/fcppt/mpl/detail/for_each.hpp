//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_FOR_EACH_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_FOR_EACH_HPP_INCLUDED

#include <fcppt/workarounds.hpp>
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
	bool Done
>
struct for_each;

template<>
struct for_each<
	true
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Fun
	>
	static void
	execute(
		Fun const &
	)
	{
	}
};

template<>
struct for_each<
	false
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Fun
	>
	static void
	execute(
		Fun const &_func
	)
	{
		typedef typename boost::mpl::deref<
			Iterator
		>::type item;

		typedef typename boost::mpl::next<
			Iterator
		>::type iter;

#ifdef FCPPT_MSVC_DEPENDANT_TEMPLATE_BUG
		_func.operator()<item>();
#else
		_func. template operator()<item>();
#endif
		fcppt::mpl::detail::for_each<
			std::is_same<
				iter,
				LastIterator
			>::value
		>:: template execute<
			iter,
			LastIterator
		>(
			_func
		);
	}
};

}
}
}

#endif
