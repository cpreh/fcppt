//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_BY_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_BY_OPT_HPP_INCLUDED

#include <fcppt/is_optional.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/algorithm/detail/find_by_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Optionally finds an element and transforms it

Returns the first element in [\a _begin, \a _end) for which \a _func doesn't
return an empty optional, if there is any. Otherwise, returns the empty
optional.

\ingroup fcpptalgorithm

\tparam Func A function callable with elements from the input sequence. It must
return an optional.
*/
template<
	typename In,
	typename Func
>
fcppt::algorithm::detail::find_by_result<
	In,
	Func
>
find_by_opt(
	In const _begin,
	In const _end,
	Func const &_func
)
{
	typedef
	fcppt::algorithm::detail::find_by_result<
		In,
		Func
	>
	result_type;

	static_assert(
		fcppt::is_optional<
			typename
			std::remove_const<
				result_type
			>::type
		>::value,
		"Func must return an optional"
	);

	for(
		In cur(
			_begin
		);
		cur != _end;
		++cur
	)
	{
		result_type result(
			_func(
				*cur
			)
		);

		if(
			result
		)
			return
				result;
	}

	return
		result_type();
}

template<
	typename Container,
	typename Func
>
fcppt::algorithm::detail::find_by_result<
	typename
	Container::iterator,
	Func
>
find_by_opt(
	Container &_container,
	Func const &_func
)
{
	return
		fcppt::algorithm::find_by_opt(
			_container.begin(),
			_container.end(),
			_func
		);
}

template<
	typename Container,
	typename Func
>
inline
fcppt::algorithm::detail::find_by_result<
	typename
	Container::const_iterator,
	Func
>
find_by_opt(
	Container const &_container,
	Func const &_func
)
{
	return
		fcppt::algorithm::find_by_opt(
			_container.begin(),
			_container.end(),
			_func
		);
}

}
}

#endif
