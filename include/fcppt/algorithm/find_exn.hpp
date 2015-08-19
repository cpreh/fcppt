//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_EXN_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_EXN_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Like std::find but throws fcppt::algorithm::element_not_found on failure

\ingroup fcpptalgorithm

\throws fcppt::algorithm::element_not_found If the element was not found
*/
template<
	typename In,
	typename T,
	typename MakeException
>
In
find_exn(
	In const _begin,
	In const _end,
	T const &_value,
	MakeException const &_make_exception
)
{
	In const ret{
		::std::find(
			_begin,
			_end,
			_value
		)
	};

	if(
		ret
		==
		_end
	)
		throw
			_make_exception();

	return
		ret;
}

template<
	typename Container,
	typename T,
	typename MakeException
>
inline
typename
Container::iterator
find_exn(
	Container &_container,
	T const &_value,
	MakeException const &_make_exception
)
{
	return
		fcppt::algorithm::find_exn(
			_container.begin(),
			_container.end(),
			_value,
			_make_exception
		);
}

template<
	typename Container,
	typename T,
	typename MakeException
>
inline
typename
Container::const_iterator
find_exn(
	Container const &_container,
	T const &_value,
	MakeException const &_make_exception
)
{
	return
		fcppt::algorithm::find_exn(
			_container.begin(),
			_container.end(),
			_value,
			_make_exception
		);
}

}
}

#endif
