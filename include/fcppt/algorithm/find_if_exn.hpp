//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_IF_EXN_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_IF_EXN_HPP_INCLUDED

#include <fcppt/algorithm/element_not_found.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Like std::find_if but throws fcppt::algorithm::element_not_found

\throws fcppt::algorithm::element_not_found If the element was not found

\ingroup fcpptalgorithm
*/
template<
	typename In,
	typename Comp
>
In
find_if_exn(
	In const _begin,
	In const _end,
	Comp const &_comp
)
{
	In const ret(
		::std::find_if(
			_begin,
			_end,
			_comp
		)
	);

	if(
		ret == _end
	)
		throw
			fcppt::algorithm::element_not_found();

	return
		ret;
}

template<
	typename Container,
	typename Comp
>
typename
Container::iterator
find_if_exn(
	Container &_container,
	Comp const &_comp
)
{
	return
		fcppt::algorithm::find_if_exn(
			_container.begin(),
			_container.end(),
			_comp
		);
}

template<
	typename Container,
	typename Comp
>
typename
Container::const_iterator
find_if_exn(
	Container const &_container,
	Comp const &_comp
)
{
	return
		fcppt::algorithm::find_if_exn(
			_container.begin(),
			_container.end(),
			_comp
		);
}

}
}

#endif
