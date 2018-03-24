//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_ASSIGN_HPP_INCLUDED
#define FCPPT_OPTIONAL_ASSIGN_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/warn_unused_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Assigns an optional and returns a reference to the optional's contents

\ingroup fcpptoptional

Assign \a _arg to \a _optional and returns a reference to \a _arg.
*/
template<
	typename Element,
	typename Arg
>
inline
Element &
assign(
	fcppt::optional::object<
		Element
	> &_optional,
	Arg &&_arg
)
FCPPT_PP_WARN_UNUSED_RESULT;

}
}

template<
	typename Element,
	typename Arg
>
inline
Element &
fcppt::optional::assign(
	fcppt::optional::object<
		Element
	> &_optional,
	Arg &&_arg
)
{
	static_assert(
		std::is_same<
			Element,
			std::remove_cv_t<
				Arg
			>
		>::value,
		"Argument type must be the same as the optional's element type"
	);

	_optional =
		fcppt::optional::object<
			Element
		>(
			std::forward<
				Arg
			>(
				_arg
			)
		);

	return
		_optional.get_unsafe();
}

#endif
