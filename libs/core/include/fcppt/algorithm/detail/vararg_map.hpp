//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_VARARG_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_VARARG_MAP_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Iterator,
	typename EndIterator,
	typename Enable = void
>
struct vararg_map;

template<
	typename Iterator,
	typename EndIterator
>
struct vararg_map<
	Iterator,
	EndIterator,
	typename
	boost::enable_if<
		std::is_same<
			Iterator,
			EndIterator
		>
	>::type
>
{
	template<
		typename AnchorFunction,
		typename ElementFunction,
		typename... Args
	>
	inline
	static
	decltype(
		auto
	)
	execute(
		AnchorFunction const &_anchor,
		ElementFunction const &,
		Args &&... _args_vararg
	)
	{
		return
			_anchor(
				std::forward<
					Args
				>(
					_args_vararg
				)...
			);
	}
};

template<
	typename Iterator,
	typename EndIterator
>
struct vararg_map<
	Iterator,
	EndIterator,
	typename
	boost::disable_if<
		std::is_same<
			Iterator,
			EndIterator
		>
	>::type
>
{
	template<
		typename AnchorFunction,
		typename ElementFunction,
		typename... Args
	>
	inline
	static
	decltype(
		auto
	)
	execute(
		AnchorFunction const &_anchor,
		ElementFunction const &_fcppt_element,
		Args &&... _args
	)
	{
		return
			fcppt::algorithm::detail::vararg_map<
				typename
				boost::mpl::next<
					Iterator
				>::type,
				EndIterator
			>::execute(
				_anchor,
				_fcppt_element,
				std::forward<
					Args
				>(
					_args
				)...,
				_fcppt_element(
					fcppt::tag<
						typename
						boost::mpl::deref<
							Iterator
						>::type
					>{}
				)
			);
	}
};

}
}
}

#endif
