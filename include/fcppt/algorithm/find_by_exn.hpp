//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_BY_EXN_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_BY_EXN_HPP_INCLUDED

#include <fcppt/optional_to_exception.hpp>
#include <fcppt/algorithm/find_by_opt.hpp>
#include <fcppt/algorithm/detail/find_by_result.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Finds an element and transforms it or throws an exception

Returns the first element in [\a _begin, \a _end) for which \a _func doesn't
return an empty optional, if there is any. Otherwise, throws the result
returned by \a _make_exception.

\ingroup fcpptalgorithm

\tparam Func A function callable with elements from the input sequence. It must
return an optional.

\tparam MakeException A nullary function returning an object type
*/
template<
	typename In,
	typename Func,
	typename MakeException
>
inline
typename
fcppt::algorithm::detail::find_by_result<
	In,
	Func
>::element_type
find_by_exn(
	In const _begin,
	In const _end,
	Func const &_func,
	MakeException const &_make_exception
)
{
	return
		fcppt::optional_to_exception(
			fcppt::algorithm::find_by_opt(
				_begin,
				_end,
				_func
			),
			_make_exception
		);
}

template<
	typename Container,
	typename Func,
	typename MakeException
>
inline
typename
fcppt::algorithm::detail::find_by_result<
	typename
	Container::iterator,
	Func
>::element_type
find_by_exn(
	Container &_container,
	Func const &_func,
	MakeException const &_make_exception
)
{
	return
		fcppt::algorithm::find_by_exn(
			_container.begin(),
			_container.end(),
			_func,
			_make_exception
		);
}

template<
	typename Container,
	typename Func,
	typename MakeException
>
inline
typename
fcppt::algorithm::detail::find_by_result<
	typename
	Container::const_iterator,
	Func
>::element_type
find_by_exn(
	Container const &_container,
	Func const &_func,
	MakeException const &_make_exception
)
{
	return
		fcppt::algorithm::find_by_exn(
			_container.begin(),
			_container.end(),
			_func,
			_make_exception
		);
}

}
}

#endif
