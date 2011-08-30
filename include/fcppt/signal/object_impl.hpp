//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/signal/object_decl.hpp>
#include <fcppt/signal/base_impl.hpp>
#include <fcppt/signal/detail/define_operator.hpp>
#include <fcppt/signal/detail/define_void_operator.hpp>
#include <fcppt/signal/detail/enable_if_void.hpp>
#include <fcppt/signal/detail/operator_limit.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <fcppt/config/external_end.hpp>

template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
fcppt::signal::object<T, Base, Enable>::object(
	combiner_type const &_combiner,
	result_type const &_initial_result
)
:
	combiner_(_combiner),
	initial_result_(_initial_result)
{}

template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
fcppt::signal::object<T, Base, Enable>::~object()
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
fcppt::signal::object<T, Base, Enable>::combiner(
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
fcppt::signal::object<T, Base, Enable>::initial_result(
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
typename fcppt::signal::object<T, Base, Enable>::result_type
fcppt::signal::object<T, Base, Enable>::operator()() const
{
	result_type result(
		initial_result_
	);

	typename base::connection_list &cur_list(
		base::connections()
	);

	for(
		typename base::connection_list::iterator it(
			cur_list.begin()
		);
		it != cur_list.end();
		++it
	)
		result =
			combiner_(
				it->function()(),
				result
			);

	return result;
}

BOOST_PP_REPEAT(
	FCPPT_SIGNAL_DETAIL_OPERATOR_LIMIT,
	FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR,
	nil
)

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
>::~object()
{
}

template<
	typename T,
	template<
		typename
	> class Base
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
>::operator()() const
{
	typename base::connection_list &cur_list(
		base::connections()
	);

	for(
		typename base::connection_list::iterator it(
			cur_list.begin()
		);
		it != cur_list.end();
		++it
	)
		it->function()();
}

BOOST_PP_REPEAT(
	FCPPT_SIGNAL_DETAIL_OPERATOR_LIMIT,
	FCPPT_SIGNAL_DETAIL_DEFINE_VOID_OPERATOR,
	nil
)

#endif
