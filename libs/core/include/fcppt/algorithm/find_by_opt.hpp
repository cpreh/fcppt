//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_BY_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_BY_OPT_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/optional/is_object.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Optionally finds an element and transforms it.

Returns the first element in \a _range for which \a _function does not return
an empty optional, if there is any. Otherwise, returns the empty optional.

\ingroup fcpptalgorithm

\tparam Function A function callable as <code>fcppt::optional::object<R>
(Range::value_type)</code>, where <code>R</code> is the result type.
*/
template<
	typename Range,
	typename Function
>
inline
auto
find_by_opt(
	Range &&_range,
	Function const &_function
)
->
decltype(
	_function(
		*_range.begin()
	)
)
{
	typedef
	fcppt::container::to_iterator_type<
		std::remove_reference_t<
			Range
		>
	>
	iterator_type;

	typedef
	decltype(
		_function(
			*_range.begin()
		)
	)
	result_type;

	static_assert(
		fcppt::optional::is_object<
			std::remove_const_t<
				result_type
			>
		>::value,
		"Function must return an optional"
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
			_function(
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
