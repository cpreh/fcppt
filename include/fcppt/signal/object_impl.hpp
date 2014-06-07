//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/signal/base_impl.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/signal/detail/enable_if_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
fcppt::signal::object<
	T,
	Base,
	Enable
>::object(
	combiner_type const &_combiner,
	result_type const &_initial_result
)
:
	combiner_(
		_combiner
	),
	initial_result_(
		_initial_result
	)
{
}

template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
fcppt::signal::object<
	T,
	Base,
	Enable
>::object(
	object &&
) = default;

template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
fcppt::signal::object<
	T,
	Base,
	Enable
> &
fcppt::signal::object<
	T,
	Base,
	Enable
>::operator=(
	object &&
) = default;

template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
fcppt::signal::object<
	T,
	Base,
	Enable
>::~object()
{
}

template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
void
fcppt::signal::object<
	T,
	Base,
	Enable
>::combiner(
	combiner_type const &_combiner
)
{
	combiner_ = _combiner;
}

template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
void
fcppt::signal::object<
	T,
	Base,
	Enable
>::initial_result(
	result_type const &_initial_result
)
{
	initial_result_ = _initial_result;
}

template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
template<
	typename... Args
>
typename fcppt::signal::object<
	T,
	Base,
	Enable
>::result_type
fcppt::signal::object<
	T,
	Base,
	Enable
>::operator()(
	Args && ..._args
)
{
	result_type result(
		initial_result_
	);

	typename base::connection_list &cur_list(
		base::connections()
	);

	for(
		auto &item : cur_list
	)
		result =
			combiner_(
				item.function()(
					std::forward<
						Args
					>(
						_args
					)...
				),
				result
			);

	return result;
}

template<
	typename T,
	template<
		typename
	> class Base
>
fcppt::signal::object<
	T,
	Base,
	typename fcppt::signal::detail::enable_if_void<
		T
	>::type
>::object()
{
}

template<
	typename T,
	template<
		typename
	> class Base
>
fcppt::signal::object<
	T,
	Base,
	typename fcppt::signal::detail::enable_if_void<
		T
	>::type
>::object(
	object  &&
) = default;

template<
	typename T,
	template<
		typename
	> class Base
>
fcppt::signal::object<
	T,
	Base,
	typename fcppt::signal::detail::enable_if_void<
		T
	>::type
> &
fcppt::signal::object<
	T,
	Base,
	typename fcppt::signal::detail::enable_if_void<
		T
	>::type
>::operator=(
	object  &&
) = default;

template<
	typename T,
	template<
		typename
	> class Base
>
fcppt::signal::object<
	T,
	Base,
	typename fcppt::signal::detail::enable_if_void<
		T
	>::type
>::~object()
{
}

template<
	typename T,
	template<
		typename
	> class Base
>
template<
	typename... Args
>
typename fcppt::signal::object<
	T,
	Base,
	typename fcppt::signal::detail::enable_if_void<
		T
	>::type
>::result_type
fcppt::signal::object<
	T,
	Base,
	typename fcppt::signal::detail::enable_if_void<
		T
	>::type
>::operator()(
	Args && ..._args
)
{
	typename base::connection_list &cur_list(
		base::connections()
	);

	for(
		auto &item : cur_list
	)
		item.function()(
			std::forward<
				Args
			>(
				_args
			)...
		);
}

#endif
