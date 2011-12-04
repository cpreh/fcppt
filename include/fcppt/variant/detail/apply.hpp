//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/type_traits/is_same.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Counter,
	bool Done
>
struct apply;

template<
	typename Counter
>
struct apply<
	Counter,
	true
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Operation,
		typename Variant
	>
	static typename Operation::result_type
	execute(
		Operation const &,
		Variant &
	)
	{
		// this code is unreachable
		std::terminate();
	}
};

template<
	typename Counter
>
struct apply<
	Counter,
	false
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Operation,
		typename Variant
	>
	static typename Operation::result_type
	execute(
		Operation const &_op,
		Variant &_obj
	)
	{
		typedef typename boost::mpl::deref<
			Iterator
		>::type item;

		typedef typename boost::mpl::next<
			Iterator
		>::type iter;

		typedef typename boost::mpl::at<
			typename Variant::types,
			Counter
		>::type type;

		return
			Counter::value == _obj.type_index()
			?
				_op(
					_obj. template get_raw<type>()
				)
			:
				detail::apply<
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
					_op,
					_obj
				);
	}
};

}
}
}

#endif
