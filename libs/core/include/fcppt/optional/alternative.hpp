//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_ALTERNATIVE_HPP_INCLUDED
#define FCPPT_OPTIONAL_ALTERNATIVE_HPP_INCLUDED

#include <fcppt/optional/detail/check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Returns the first optional if it is not nothing

\ingroup fcpptoptional

If \a _optional1 is not nothing, the result is \a _optional1, otherwise
the result of \a _optional2 is returned.

\tparam Function A function callable as <code>Optional ()</code>.
*/
template<
	typename Optional,
	typename Function
>
std::remove_reference_t<
	Optional
>
alternative(
	Optional &&_optional1,
	Function const &_optional2
)
{
	static_assert(
		fcppt::optional::detail::check<
			Optional
		>::value,
		"optional_alternative must return an optional"
	);

	static_assert(
		fcppt::optional::detail::check<
			std::result_of_t<
				Function()
			>
		>::value,
		"Function must return an optional"
	);

	return
		_optional1.has_value()
		?
			std::forward<
				Optional
			>(
				_optional1
			)
		:
			_optional2()
		;
}

}
}

#endif
