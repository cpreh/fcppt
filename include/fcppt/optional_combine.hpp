//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_COMBINE_HPP_INCLUDED
#define FCPPT_OPTIONAL_COMBINE_HPP_INCLUDED

#include <fcppt/forward_optional_get.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/detail/check_optional.hpp>


namespace fcppt
{

/**
\brief Combines two optionals

\ingroup fcpptoptional

If \a _optional1 is set to x1 and \a _optional2 is set to x2, then
<code>Optional(_function(x1, x2))</code>. Otherwise, if at least one optional
is set, that optional is returned.
*/
template<
	typename Optional,
	typename Function
>
auto
optional_combine(
	Optional &&_optional1,
	Optional &&_optional2,
	Function const &_function
)
->
fcppt::optional<
	decltype(
		_function(
			fcppt::forward_optional_get<
				Optional
			>(
				_optional1.get_unsafe()
			),
			fcppt::forward_optional_get<
				Optional
			>(
				_optional2.get_unsafe()
			)
		)
	)
>
{
	typedef
	fcppt::optional<
		decltype(
			_function(
				fcppt::forward_optional_get<
					Optional
				>(
					_optional1.get_unsafe()
				),
				fcppt::forward_optional_get<
					Optional
				>(
					_optional2.get_unsafe()
				)
			)
		)
	>
	result_type;

	static_assert(
		fcppt::detail::check_optional<
			Optional
		>::value,
		"Optional must be an optional"
	);

	if(
		!_optional1
	)
		return
			result_type{
				fcppt::move_if_rvalue<
					Optional
				>(
					_optional2
				)
			};

	if(
		!_optional2
	)
		return
			result_type{
				fcppt::move_if_rvalue<
					Optional
				>(
					_optional1
				)
			};

	return
		result_type{
			_function(
				fcppt::forward_optional_get<
					Optional
				>(
					_optional1.get_unsafe()
				),
				fcppt::forward_optional_get<
					Optional
				>(
					_optional2.get_unsafe()
				)
			)
		};
}

}

#endif
