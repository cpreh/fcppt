//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_MAYBE_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAYBE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/detail/check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Transforms an optional value or returns a default value

\ingroup fcpptoptional

For the lack of a better name, this function is called maybe like in Haskell.
If \a _optional is set to x, then <code>_transform(x)</code> is returned.
Otherwise, the result of \a _default is returned. This implies that \a
_transform and \a _default must return the same type Ret. \a _optional can be
perfectly forwarded into \a _transform, i.e. the optional's contents will be
moved iff \a _optional is an rvalue.

\tparam Default Must be a function of type <code>Ret ()</code>

\tparam Transform Must be a function of type <code>Ret (Optional::value_type)</code>
*/
template<
	typename Optional,
	typename Default,
	typename Transform
>
typename
std::result_of<
	Default()
>::type
maybe(
	Optional &&_optional,
	Default const _default,
	Transform const _transform
)
{
	static_assert(
		fcppt::optional::detail::check<
			Optional
		>::value,
		"Optional must be an optional"
	);

	static_assert(
		std::is_same<
			decltype(
				_default()
			),
			decltype(
				_transform(
					fcppt::move_if_rvalue<
						Optional
					>(
						_optional.get_unsafe()
					)
				)
			)
		>::value,
		"Default and Transform must return the same type"
	);

	return
		_optional.has_value()
		?
			_transform(
				fcppt::move_if_rvalue<
					Optional
				>(
					_optional.get_unsafe()
				)
			)
		:
			_default()
		;
}

}
}

#endif
