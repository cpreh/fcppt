//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_FOR_EACH_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_FOR_EACH_HPP_INCLUDED

#include <fcppt/workarounds.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/type_traits/is_same.hpp>
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
	{}
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
		Fun const &f
	)
	{
		typedef typename boost::mpl::deref<Iterator>::type item;
		typedef typename boost::mpl::next<Iterator>::type iter;

#ifdef FCPPT_MSVC_DEPENDANT_TEMPLATE_BUG
		f.operator()<item>();
#else
		f. template operator()<item>();
#endif
		detail::for_each<
			boost::is_same<
				iter,
				LastIterator
			>::value
		>:: template execute<
			iter,
			LastIterator
		>(
			f
		);
	}
};

}
}
}

#endif
