//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_BIND_CONSTRUCT_HPP_INCLUDED
#define FCPPT_OPTIONAL_BIND_CONSTRUCT_HPP_INCLUDED

#include <fcppt/optional_bind.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts an optional of one type to another and applies the optional
constructor

\ingroup fcpptoptional

\see fcppt::optional_bind
*/
template<
	typename Optional,
	typename Function
>
inline
auto
optional_bind_construct(
	Optional &&_source,
	Function const &_function
)
->
fcppt::optional<
	typename
	std::remove_cv<
		decltype(
			_function(
				fcppt::forward_optional_get<
					Optional
				>(
					_source.get_unsafe()
				)
			)
		)
	>::type
>
{
	typedef
	decltype(
		fcppt::forward_optional_get<
			Optional
		>(
			_source.get_unsafe()
		)
	)
	arg_type;

	typedef
	fcppt::optional<
		typename
		std::remove_cv<
			typename
			std::result_of<
				Function(
					arg_type
				)
			>::type
		>::type
	>
	result_type;

	return
		fcppt::optional_bind(
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

#endif
