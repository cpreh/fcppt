//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_BIND_CONSTRUCT_HPP_INCLUDED
#define FCPPT_OPTIONAL_BIND_CONSTRUCT_HPP_INCLUDED

#include <fcppt/optional_bind.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
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
	typename Source,
	typename Function
>
inline
fcppt::optional<
	typename
	std::result_of<
		Function(
			Source
		)
	>::type
>
optional_bind_construct(
	fcppt::optional<
		Source
	> const &_source,
	Function const &_function
)
{
	typedef
	fcppt::optional<
		typename
		std::result_of<
			Function(
				Source
			)
		>::type
	>
	result_type;

	return
		fcppt::optional_bind(
			_source,
			[
				&_function
			](
				Source const &_arg
			)
			{
				return
					result_type(
						_function(
							_arg
						)
					);
			}
		);
}

}

#endif
