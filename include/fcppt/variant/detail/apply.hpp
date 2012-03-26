//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
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
	bool Done
>
struct apply;

template<>
struct apply<
	true
>
{
	template<
		typename Counter,
		typename Iterator,
		typename EndIterator,
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

template<>
struct apply<
	false
>
{
	template<
		typename Counter,
		typename Iterator,
		typename EndIterator,
		typename Operation,
		typename Variant
	>
	static typename Operation::result_type
	execute(
		Operation const &_op,
		Variant &_obj
	)
	{
		typedef typename boost::mpl::next<
			Iterator
		>::type next_iterator;

		return
			Counter::value == _obj.type_index()
			?
				_op(
					_obj. template get_raw<
						typename boost::mpl::deref<
							Iterator
						>::type
					>()
				)
			:
				fcppt::variant::detail::apply<
					boost::is_same<
						next_iterator,
						EndIterator
					>::value
				>:: template execute<
					typename boost::mpl::next<
						Counter
					>::type,
					next_iterator,
					EndIterator
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
