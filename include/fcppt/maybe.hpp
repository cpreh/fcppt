//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAYBE_HPP_INCLUDED
#define FCPPT_MAYBE_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Transforms an optional value or returns a default value

\ingroup fcpptoptional

For the lack of a better name, this function is called maybe like in Haskell.
If \a _optional is set to x, then <code>_transform(x)</code> is returned.
Otherwise, the result of \a _default is returned. This implies that
\a _transform and \a _default must return the same type Ret.

\tparam Default Must be a function of type <code>Ret ()</code>

\tparam Transform Must be a function of type <code>Ret (Type)</code>
*/
template<
	typename Type,
	typename Default,
	typename Transform
>
typename
std::result_of<
	Default()
>::type
maybe(
	fcppt::optional<
		Type
	> const &_optional,
	Default const _default,
	Transform const _transform
)
{
	static_assert(
		std::is_same<
			decltype(
				_default()
			),
			decltype(
				_transform(
					_optional.get_unsafe()
				)
			)
		>::value,
		"Default and Transform must return the same type"
	);

	return
		_optional
		?
			_transform(
				_optional.get_unsafe()
			)
		:
			_default()
		;
}

}

#endif
