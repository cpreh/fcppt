//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_BY_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_BY_OPT_HPP_INCLUDED

#include <fcppt/is_optional.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/algorithm/detail/find_by_result.hpp>
#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Optionally finds an element and transforms it

Returns the first element in \a _range for which \a _func does not return an
empty optional, if there is any. Otherwise, returns the empty optional.

\ingroup fcpptalgorithm

\tparam Func A function callable with elements from the input sequence. It must
return an optional.
*/
template<
	typename Range,
	typename Func
>
inline
fcppt::algorithm::detail::find_by_result<
	fcppt::container::to_iterator_type<
		typename
		std::remove_reference<
			Range
		>::type
	>,
	Func
>
find_by_opt(
	Range &&_range,
	Func const &_func
)
{
	typedef
	fcppt::container::to_iterator_type<
		typename
		std::remove_reference<
			Range
		>::type
	>
	iterator_type;

	typedef
	fcppt::algorithm::detail::find_by_result<
		iterator_type,
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

	iterator_type const end(
		_range.end()
	);

	for(
		iterator_type cur(
			_range.begin()
		);
		cur != end;
		++cur
	)
	{
		result_type result(
			_func(
				*cur
			)
		);

		if(
			result.has_value()
		)
			return
				result;
	}

	return
		result_type();
}

}
}

#endif
