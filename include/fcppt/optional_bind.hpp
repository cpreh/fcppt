//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_BIND_HPP_INCLUDED
#define FCPPT_OPTIONAL_BIND_HPP_INCLUDED

#include <fcppt/is_optional.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts an optional of one type to another

\ingroup fcpptoptional

Converts \a _source into the optional type returned by \a _function. If \a
_source is empty, the empty optional is returned. Otherwise, \a _source is
dereferenced and the result from applying \a _function is returned.

\param _source The optional to convert

\param _function The function to apply to the value inside \a _source. It must
accept a type of \a Source.
*/
template<
	typename Source,
	typename Function
>
inline
typename
std::result_of<
	Function(
		Source
	)
>::type
optional_bind(
	fcppt::optional<
		Source
	> const &_source,
	Function const &_function
)
{
	typedef
	typename
	std::decay<
		typename
		std::result_of<
			Function(
				Source
			)
		>::type
	>::type
	result_type;

	static_assert(
		fcppt::is_optional<
			result_type
		>::value,
		"optional_bind must return an optional"
	);

	return
		_source
		?
			_function(
				*_source
			)
		:
			result_type{}
		;
}

}

#endif
