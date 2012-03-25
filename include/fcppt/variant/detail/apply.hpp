//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/size.hpp>
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
		typename Operation,
		typename Variant
	>
	static typename Operation::result_type
	execute(
		Operation const &_op,
		Variant &_obj
	)
	{
		typedef typename Variant::types types;

		typedef typename boost::mpl::next<
			Counter
		>::type next_counter;

		return
			Counter::value == _obj.type_index()
			?
				_op(
					_obj. template get_raw<
						typename boost::mpl::at<
							types,
							Counter
						>::type
					>()
				)
			:
				fcppt::variant::detail::apply<
					next_counter,
					boost::mpl::equal_to<
						next_counter,
						boost::mpl::size<
							types
						>
					>::value
				>::execute(
					_op,
					_obj
				);
	}
};

}
}
}

#endif
