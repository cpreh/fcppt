//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_COMBINE_HPP_INCLUDED
#define FCPPT_OPTIONAL_COMBINE_HPP_INCLUDED

#include <fcppt/optional/forward_get.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/detail/check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
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
combine(
	Optional &&_optional1,
	Optional &&_optional2,
	Function const &_function
)
->
fcppt::optional::object<
	decltype(
		_function(
			fcppt::optional::forward_get<
				Optional
			>(
				_optional1.get_unsafe()
			),
			fcppt::optional::forward_get<
				Optional
			>(
				_optional2.get_unsafe()
			)
		)
	)
>
{
	typedef
	fcppt::optional::object<
		decltype(
			_function(
				fcppt::optional::forward_get<
					Optional
				>(
					_optional1.get_unsafe()
				),
				fcppt::optional::forward_get<
					Optional
				>(
					_optional2.get_unsafe()
				)
			)
		)
	>
	result_type;

	static_assert(
		fcppt::optional::detail::check<
			Optional
		>::value,
		"Optional must be an optional"
	);

	if(
		!_optional1.has_value()
	)
		return
			result_type{
				std::forward<
					Optional
				>(
					_optional2
				)
			};

	if(
		!_optional2.has_value()
	)
		return
			result_type{
				std::forward<
					Optional
				>(
					_optional1
				)
			};

	return
		result_type{
			_function(
				fcppt::optional::forward_get<
					Optional
				>(
					_optional1.get_unsafe()
				),
				fcppt::optional::forward_get<
					Optional
				>(
					_optional2.get_unsafe()
				)
			)
		};
}

}
}

#endif
