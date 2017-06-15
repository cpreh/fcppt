//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_VARARG_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_VARARG_MAP_HPP_INCLUDED

#include <fcppt/move_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/fusion/iterator/next.hpp>
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
	bool Move,
	typename Iterator,
	typename EndIterator,
	typename Enable = void
>
struct vararg_map;

template<
	bool Move,
	typename Iterator,
	typename EndIterator
>
struct vararg_map<
	Move,
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
		Iterator,
		EndIterator,
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
	bool Move,
	typename Iterator,
	typename EndIterator
>
struct vararg_map<
	Move,
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
		Iterator const _cur,
		EndIterator const _end,
		AnchorFunction const &_fcppt_anchor_function,
		ElementFunction const &_fcppt_element_function,
		Args &&... _args
	)
	{
		return
			fcppt::algorithm::detail::vararg_map<
				Move,
				typename
				boost::fusion::result_of::next<
					Iterator
				>::type,
				EndIterator
			>::execute(
				boost::fusion::next(
					_cur
				),
				_end,
				_fcppt_anchor_function,
				_fcppt_element_function,
				std::forward<
					Args
				>(
					_args
				)...,
				_fcppt_element_function(
					fcppt::move_if<
						Move
					>(
						boost::fusion::deref(
							_cur
						)
					)
				)
			);
	}
};

}
}
}

#endif
