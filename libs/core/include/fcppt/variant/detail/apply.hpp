//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/brigand/invoke_on.hpp>
#include <fcppt/container/tuple/to_varargs.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/detail/get_unsafe.hpp>
#include <fcppt/variant/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Function,
	typename FailFunction,
	typename... Args
>
decltype(
	auto
)
apply(
	Function const &_function,
	FailFunction const &,
	std::tuple<
		Args...
	> &&_tuple
)
{
	return
		fcppt::container::tuple::to_varargs(
			std::move(
				_tuple
			),
			[
				&_function
			](
				auto &&... _inner_args
			)
			{
				return
					_function(
						std::forward<
							decltype(
								_inner_args
							)
						>(
							_inner_args
						)...
					);
			}
		);
}

template<
	typename Function,
	typename FailFunction,
	typename... Args,
	typename Variant1,
	typename... Variants
>
decltype(
	auto
)
apply(
	Function const &_function,
	FailFunction const &_fail_function,
	std::tuple<
		Args...
	> &&_args,
	Variant1 &&_variant1,
	Variants &&... _variants
)
{
	return
		fcppt::brigand::invoke_on<
			fcppt::variant::types_of<
				fcppt::type_traits::remove_cv_ref_t<
					Variant1
				>
			>
		>(
			_variant1.type_index(),
			[
				&_function,
				&_args,
				&_fail_function,
				&_variant1,
				&_variants...
			](
				auto const _type
			)
			{
				FCPPT_USE(
					_type
				);

				return
					fcppt::variant::detail::apply(
						_function,
						_fail_function,
						std::tuple_cat(
							std::move(
								_args
							),
							std::forward_as_tuple(
								fcppt::move_if_rvalue<
									Variant1
								>(
									fcppt::variant::detail::get_unsafe<
										fcppt::tag_type<
											decltype(
												_type
											)
										>
									>(
										_variant1
									)
								)
							)
						),
						std::forward<
							Variants
						>(
							_variants
						)...
					);
			},
			_fail_function
		);
}

}
}
}

#endif
