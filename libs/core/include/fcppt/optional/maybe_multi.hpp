//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_MAYBE_MULTI_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAYBE_MULTI_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/detail/has_value_all.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Transforms multiple optional values or returns a default value

\ingroup fcpptoptional

A multi version of \ref fcppt::optional::maybe. Unfortunately, the variadic template
arguments must come last.
*/
template<
	typename Default,
	typename Transform,
	typename... Optionals
>
std::result_of_t<
	Default()
>
maybe_multi(
	Default const _default,
	Transform const _transform,
	Optionals &&... _optionals
)
{
	static_assert(
		std::is_same<
			decltype(
				_default()
			),
			decltype(
				_transform(
					fcppt::move_if_rvalue<
						Optionals
					>(
						_optionals.get_unsafe()
					)...
				)
			)
		>::value,
		"Default and Transform must return the same type"
	);

	return
		fcppt::optional::detail::has_value_all(
			_optionals...
		)
		?
			_transform(
				fcppt::move_if_rvalue<
					Optionals
				>(
					_optionals.get_unsafe()
				)...
			)
		:
			_default()
		;
}

}
}

#endif
