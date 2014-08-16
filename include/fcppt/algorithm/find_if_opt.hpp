//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_IF_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_IF_OPT_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Like std::find_if but returns an empty optional on failure

\ingroup fcpptalgorithm
*/
template<
	typename In,
	typename Comp
>
fcppt::optional<
	typename std::iterator_traits<
		In
	>::reference
>
find_if_opt(
	In const _begin,
	In const _end,
	Comp const &_comp
)
{
	typedef
	fcppt::optional<
		typename std::iterator_traits<
			In
		>::reference
	>
	result_type;

	In const ret(
		::std::find_if(
			_begin,
			_end,
			_comp
		)
	);

	return
		ret
		==
		_end
		?
			result_type()
		:
			result_type(
				*ret
			)
		;
}

template<
	typename Container,
	typename Comp
>
fcppt::optional<
	typename
	Container::reference
>
find_if_opt(
	Container &_container,
	Comp const &_comp
)
{
	return
		fcppt::algorithm::find_if_opt(
			_container.begin(),
			_container.end(),
			_comp
		);
}

template<
	typename Container,
	typename Comp
>
fcppt::optional<
	typename
	Container::const_reference
>
find_if_opt(
	Container const &_container,
	Comp const &_comp
)
{
	return
		fcppt::algorithm::find_if_opt(
			_container.begin(),
			_container.end(),
			_comp
		);
}

}
}

#endif
