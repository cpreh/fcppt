//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CAT_OPTIONALS_HPP_INCLUDED
#define FCPPT_ALGORITHM_CAT_OPTIONALS_HPP_INCLUDED

#include <fcppt/is_optional_reference.hpp>
#include <fcppt/maybe_void.hpp>
#include <fcppt/move_if.hpp>
#include <fcppt/algorithm/range_element_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Removes empty optionals from a range

\ingroup fcpptalgorithm

For every element \em e in \a _source, if \em e is set to <code>x</code>, then
<code>x</code> is inserted into the target container.

\tparam Source Must be a container of optionals

\tparam TargetContainer Must be a container whose value type matches that of
the optionals from \a Source
*/
template<
	typename TargetContainer,
	typename Source
>
TargetContainer
cat_optionals(
	Source &&_source
)
{
	TargetContainer result;

	for(
		fcppt::algorithm::range_element_type<
			Source
		> element
		:
		_source
	)
		fcppt::maybe_void(
			element,
			[
				&result
			](
				auto &&_element
			)
			{
				result.insert(
					result.end(),
					fcppt::move_if<
						!fcppt::is_optional_reference<
							decltype(
								element
							)
						>::value
						&&
						!std::is_lvalue_reference<
							Source
						>::value
					>(
						_element
					)
				);
			}
		);

	return
		result;
}

}
}

#endif
