//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_APPLY_HPP_INCLUDED
#define FCPPT_OPTIONAL_APPLY_HPP_INCLUDED

#include <fcppt/optional/forward_get.hpp>
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
\brief Applies a function to multiple optionals or returns nothing

\ingroup fcpptoptional

If \a _optionals, <code>o_1,...,o_n</code> are set to <code>x_1,...,x_n</code>,
then <code>_function(x_1,...,x_n)</code> is returned. Otherwise, the empty
optional is returned.

\tparam Function A function callable as <code>R (Optionals::value_type...)</code>
where <code>R</code> is the result type

\tparam Optionals A parameter pack of optionals
*/
template<
	typename Function,
	typename... Optionals
>
inline
auto
apply(
	Function const &_function,
	Optionals &&... _optionals
)
->
fcppt::optional::object<
	decltype(
		_function(
			fcppt::optional::forward_get<
				Optionals
			>(
				_optionals.get_unsafe()
			)...
		)
	)
>
{
	typedef
	fcppt::optional::object<
		decltype(
			_function(
				fcppt::optional::forward_get<
					Optionals
				>(
					_optionals.get_unsafe()
				)...
			)
		)
	>
	result_type;

	return
		fcppt::optional::detail::has_value_all(
			_optionals...
		)
		?
			result_type(
				_function(
					fcppt::optional::forward_get<
						Optionals
					>(
						_optionals.get_unsafe()
					)...
				)
			)
		:
			result_type{}
		;
}

}
}

#endif
