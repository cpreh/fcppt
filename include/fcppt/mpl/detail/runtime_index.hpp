//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_RUNTIME_INDEX_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_RUNTIME_INDEX_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/next.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{
namespace detail
{

/// \cond

template<
	typename MaxIndex,
	typename CurrentIndex,
	typename Enable = void
>
struct runtime_index;

template<
	typename MaxIndex,
	typename CurrentIndex
>
struct runtime_index<
	MaxIndex,
	CurrentIndex,
	typename
	std::enable_if<
		CurrentIndex::value
		==
		MaxIndex::value
	>::type
>
{
	template<
		typename Index,
		typename Function,
		typename FailFunction
	>
	static
	decltype(
		auto
	)
	execute(
		Index,
		Function const &,
		FailFunction const &_fail_function
	)
	{
		return
			_fail_function();
	}
};

template<
	typename MaxIndex,
	typename CurrentIndex
>
struct runtime_index<
	MaxIndex,
	CurrentIndex,
	typename
	std::enable_if<
		CurrentIndex::value
		!=
		MaxIndex::value
	>::type
>
{
	template<
		typename Index,
		typename Function,
		typename FailFunction
	>
	static
	decltype(
		auto
	)
	execute(
		Index const _index,
		Function const &_function,
		FailFunction const &_fail_function
	)
	{
		return
			_index
			==
			CurrentIndex::value
			?
				_function(
					CurrentIndex()
				)
			:
				fcppt::mpl::detail::runtime_index<
					MaxIndex,
					typename
					boost::mpl::next<
						CurrentIndex
					>::type
				>::execute(
					_index,
					_function,
					_fail_function
				)
			;
	}
};

/// \endcond

}
}
}

#endif
