//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_MONAD_HPP_INCLUDED
#define FCPPT_EITHER_MONAD_HPP_INCLUDED

#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/monad/instance_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace monad
{

template<
	typename Failure,
	typename Success
>
struct instance<
	fcppt::either::object<
		Failure,
		Success
	>
>
{
	template<
		typename Type
	>
	struct constructor
	{
		using
		type
		=
		fcppt::either::object<
			Failure,
			Type
		>;
	};

	template<
		typename Either
	>
	struct inner_type
	{
		using
		type
		=
		fcppt::either::success_type<
			Either
		>;
	};

	template<
		typename Value
	>
	static
	auto
	return_(
		Value &&_value
	)
	{
		return
			fcppt::either::make_success<
				Failure
			>(
				std::forward<
					Value
				>(
					_value
				)
			);
	}


	template<
		typename Either,
		typename Function
	>
	static
	auto
	bind(
		Either &&_either,
		Function const &_function
	)
	{
		return
			fcppt::either::bind(
				std::forward<
					Either
				>(
					_either
				),
				_function
			);
	}
};

}
}

#endif
