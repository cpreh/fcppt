//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_MAP_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Maps over an optional using a function

\ingroup fcpptoptional

If \a _source is set to <code>x</code>, then
<code>optional(_function(x))</code> is returned. Otherwise, the empty optional
is returned.

\tparam Function A function callable as <code>R (Optional::value_type)</code>
where <code>R</code> is the result type
*/
template<
	typename Optional,
	typename Function
>
inline
auto
map(
	Optional &&_source,
	Function const &_function
)
->
fcppt::optional::object<
	std::remove_cv_t<
		decltype(
			_function(
				fcppt::move_if_rvalue<
					Optional
				>(
					_source.get_unsafe()
				)
			)
		)
	>
>
{
	typedef
	decltype(
		fcppt::move_if_rvalue<
			Optional
		>(
			_source.get_unsafe()
		)
	)
	arg_type;

	typedef
	fcppt::optional::object<
		std::remove_cv_t<
			std::result_of_t<
				Function(
					arg_type
				)
			>
		>
	>
	result_type;

	return
		fcppt::optional::bind(
			std::forward<
				Optional
			>(
				_source
			),
			[
				&_function
			](
				arg_type _arg
			)
			{
				return
					result_type(
						_function(
							std::forward<
								arg_type
							>(
								_arg
							)
						)
					);
			}
		);
}

}
}

#endif
