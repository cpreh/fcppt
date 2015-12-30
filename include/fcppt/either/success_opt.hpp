//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_SUCCESS_OPT_HPP_INCLUDED
#define FCPPT_EITHER_SUCCESS_OPT_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Returns the success type as an optional

\ingroup fcppteither
*/
template<
	typename Either
>
fcppt::optional<
	typename
	std::decay<
		Either
	>::type::success
>
success_opt(
	Either &&_either
)
{
	typedef
	typename
	std::decay<
		Either
	>::type
	either;

	static_assert(
		fcppt::either::is_object<
			either
		>::value,
		"Either must be an either"
	);

	typedef
	fcppt::optional<
		typename
		either::success
	>
	result_type;

	return
		_either.has_success()
		?
			result_type(
				fcppt::move_if_rvalue<
					Either
				>(
					_either.get_success_unsafe()
				)
			)
		:
			result_type()
		;
}

}
}

#endif
