//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_IF_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_IF_OPT_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Like <code>std::find_if</code> but returns an empty optional on failure.

\ingroup fcpptalgorithm

\tparam Comp Must be a function callable as <code>bool (Range::value_type)</code>.
*/
template<
	typename Range,
	typename Comp
>
inline
fcppt::optional::object<
	fcppt::container::to_iterator_type<
		std::remove_reference_t<
			Range
		>
	>
>
find_if_opt(
	Range &&_range,
	Comp const &_comp
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
	fcppt::optional::object<
		iterator_type
	>
	result_type;

	iterator_type const end{
		_range.end()
	};

	iterator_type const ret(
		::std::find_if(
			_range.begin(),
			end,
			_comp
		)
	);

	return
		ret
		==
		end
		?
			result_type()
		:
			result_type(
				ret
			)
		;
}

}
}

#endif
