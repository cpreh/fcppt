//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_BIND_HPP_INCLUDED
#define FCPPT_OPTIONAL_BIND_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/detail/check.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
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
	typename Optional,
	typename Function
>
inline
auto
bind(
	Optional &&_source,
	Function const &_function
)
->
std::remove_reference_t<
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
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
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
	result_type;

	static_assert(
		fcppt::optional::detail::check<
			result_type
		>::value,
		"optional_bind must return an optional"
	);

	return
		_source.has_value()
		?
			_function(
				fcppt::move_if_rvalue<
					Optional
				>(
					_source.get_unsafe()
				)
			)
		:
			result_type{}
		;
}

}
}

#endif
