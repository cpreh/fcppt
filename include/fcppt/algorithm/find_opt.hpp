//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_OPT_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Like std::find but returns an empty optional on failure

\ingroup fcpptalgorithm
*/
template<
	typename In,
	typename T
>
fcppt::optional<
	In
>
find_opt(
	In const _begin,
	In const _end,
	T const &_value
)
{
	typedef
	fcppt::optional<
		In
	>
	result_type;

	In const ret(
		::std::find(
			_begin,
			_end,
			_value
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
				ret
			)
		;
}

template<
	typename Container,
	typename T
>
fcppt::optional<
	typename
	Container::iterator
>
inline
find_opt(
	Container &_container,
	T const &_value
)
{
	return
		fcppt::algorithm::find_opt(
			_container.begin(),
			_container.end(),
			_value
		);
}

template<
	typename Container,
	typename T
>
fcppt::optional<
	typename
	Container::const_iterator
>
inline
find_opt(
	Container const &_container,
	T const &_value
)
{
	return
		fcppt::algorithm::find_opt(
			_container.begin(),
			_container.end(),
			_value
		);
}

}
}

#endif
