//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_DETAIL_MAKE_OPT_HPP_INCLUDED
#define FCPPT_ASSIGN_DETAIL_MAKE_OPT_HPP_INCLUDED

#include <fcppt/optional/is_object.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace assign
{
namespace detail
{

template<
	typename Result,
	typename Arg
>
inline
typename
std::enable_if<
	!fcppt::optional::is_object<
		typename
		std::decay<
			Arg
		>::type
	>::value,
	Result
>::type
make_opt(
	Result &&_result,
	Arg &&_arg
)
{
	_result.insert(
		_result.end(),
		std::forward<
			Arg
		>(
			_arg
		)
	);

	return
		std::move(
			_result
		);
}

template<
	typename Result,
	typename Arg
>
inline
typename
std::enable_if<
	fcppt::optional::is_object<
		typename
		std::decay<
			Arg
		>::type
	>::value,
	Result
>::type
make_opt(
	Result &&_result,
	Arg &&_arg
)
{
	return
		_arg.has_value()
		?
			fcppt::assign::detail::make_opt(
				std::move(
					_result
				),
				std::move(
					_arg.get_unsafe()
				)
			)
		:
			std::move(
				_result
			)
		;
}

template<
	typename Result,
	typename Arg
>
inline
typename
std::enable_if<
	fcppt::optional::is_object<
		typename
		std::decay<
			Arg
		>::type
	>::value,
	Result
>::type
make_opt(
	Result &&_result,
	Arg const &_arg
)
{
	return
		_arg.has_value()
		?
			fcppt::assign::detail::make_opt(
				std::move(
					_result
				),
				_arg.get_unsafe()
			)
		:
			std::move(
				_result
			)
		;
}

}
}
}

#endif
