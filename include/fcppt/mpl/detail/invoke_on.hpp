//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_INVOKE_ON_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_INVOKE_ON_HPP_INCLUDED

#include <fcppt/workarounds.hpp>
#include <fcppt/mpl/invalid_invoke.hpp>
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
	typename Counter,
	bool Done
>
struct invoke_on;

template<
	typename Counter
>
struct invoke_on<
	Counter,
	true
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Index,
		typename Operation
	>
	static typename Operation::result_type
	execute(
		Index const &,
		Operation const &
	)
	{
		throw invalid_invoke();
	}
};

template<
	typename Counter
>
struct invoke_on<
	Counter,
	false
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Index,
		typename Operation
	>
	static typename Operation::result_type
	execute(
		Index const &index,
		Operation const &op
	)
	{
		typedef typename boost::mpl::deref<
			Iterator
		>::type item;

		typedef typename boost::mpl::next<
			Iterator
		>::type iter;

		return Counter::value == index
			?
#ifdef FCPPT_MSVC_DEPENDANT_TEMPLATE_BUG
			op.operator()<
				item
			>()
#else

			op. template operator()<
				item
			>()
#endif
			: detail::invoke_on<
				typename boost::mpl::next<
					Counter
				>::type,
				boost::is_same<
					iter,
					LastIterator
				>::value
			>:: template execute<
				iter,
				LastIterator
			>(
				index,
				op
			);
	}
};

}
}
}

#endif
