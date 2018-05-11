//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRODUCT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_PRODUCT_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_apply.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/set_intersection.hpp>
#include <fcppt/algorithm/set_union.hpp>
#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/product_decl.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/detail/combine_errors.hpp>
#include <fcppt/options/detail/duplicate_names_text.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/multiply_disjoint.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::product(
	Left const &_left,
	Right const &_right
)
:
	left_(
		_left
	),
	right_(
		_right
	)
{
	this->check_disjoint();
}

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::product(
	Left &&_left,
	Right &&_right
)
:
	left_(
		std::move(
			_left
		)
	),
	right_(
		std::move(
			_right
		)
	)
{
	this->check_disjoint();
}

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::product(
	product const &
)
= default;

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::product(
	product &&
)
= default;

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
> &
fcppt::options::product<
	Left,
	Right
>::operator=(
	product const &
)
= default;

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
> &
fcppt::options::product<
	Left,
	Right
>::operator=(
	product &&
)
= default;

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::~product()
{
}

template<
	typename Left,
	typename Right
>
fcppt::options::result<
	typename
	fcppt::options::product<
		Left,
		Right
	>::result_type
>
fcppt::options::product<
	Left,
	Right
>::parse(
	fcppt::options::parse_arguments &_state
) const
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)
	return
		fcppt::either::match(
			fcppt::options::deref(
				left_
			).parse(
				_state
			),
			[
				&_state,
				this
			](
				fcppt::options::error &&_error
			)
			{
				return
					fcppt::options::result<
						result_type
					>{
						fcppt::optional::maybe(
							fcppt::either::failure_opt(
								fcppt::options::deref(
									right_
								).parse(
									_state
								)
							),
							[
								&_error
							]()
							->
							fcppt::options::error
							{
								return
									std::move(
										_error
									);
							},
							[
								&_error
							](
								fcppt::options::error &&_other_error
							)
							->
							fcppt::options::error
							{
								return
									fcppt::options::detail::combine_errors(
										std::move(
											_error
										),
										std::move(
											_other_error
										)
									);
							}
						)
					};
			},
			[
				&_state,
				this
			](
				fcppt::options::result_of<
					Left
				> &&_left_result
			)
			{
				return
					fcppt::either::map(
						fcppt::options::deref(
							right_
						).parse(
							_state
						),
						[
							&_left_result
						](
							fcppt::options::result_of<
								Right
							> &&_right_result
						)
						{
							return
								fcppt::record::multiply_disjoint(
									std::move(
										_left_result
									),
									std::move(
										_right_result
									)
								);
						}
					);
			}
		);
FCPPT_PP_POP_WARNING
}

template<
	typename Left,
	typename Right
>
fcppt::options::flag_name_set
fcppt::options::product<
	Left,
	Right
>::flag_names() const
{
	return
		fcppt::strong_typedef_apply(
			[](
				fcppt::options::name_set const &_left_set,
				fcppt::options::name_set const &_right_set
			)
			{
				return
					fcppt::algorithm::set_union(
						_left_set,
						_right_set
					);
			},
			fcppt::options::deref(
				left_
			).flag_names(),
			fcppt::options::deref(
				right_
			).flag_names()
		);
}

template<
	typename Left,
	typename Right
>
fcppt::options::option_name_set
fcppt::options::product<
	Left,
	Right
>::option_names() const
{
	return
		fcppt::strong_typedef_apply(
			[](
				fcppt::options::name_set const &_left_set,
				fcppt::options::name_set const &_right_set
			)
			{
				return
					fcppt::algorithm::set_union(
						_left_set,
						_right_set
					);
			},
			fcppt::options::deref(
				left_
			).option_names(),
			fcppt::options::deref(
				right_
			).option_names()
		);
}

template<
	typename Left,
	typename Right
>
fcppt::string
fcppt::options::product<
	Left,
	Right
>::usage() const
{
	return
		fcppt::options::deref(
			left_
		).usage()
		+
		FCPPT_TEXT('\n')
		+
		fcppt::options::deref(
			right_
		).usage();
}

template<
	typename Left,
	typename Right
>
void
fcppt::options::product<
	Left,
	Right
>::check_disjoint() const
{
	auto const all_parameters(
		[](
			auto const &_parser
		)
		->
		fcppt::options::name_set
		{
			return
				fcppt::algorithm::set_union(
					_parser.flag_names().get(),
					_parser.option_names().get()
				);
		}
	);

	fcppt::options::name_set const common_names{
		fcppt::algorithm::set_intersection(
			all_parameters(
				fcppt::options::deref(
					left_
				)
			),
			all_parameters(
				fcppt::options::deref(
					right_
				)
			)
		)
	};

	if(
		!common_names.empty()
	)
		throw
			fcppt::options::duplicate_names{
				fcppt::options::detail::duplicate_names_text(
					common_names
				)
			};
}

#endif
