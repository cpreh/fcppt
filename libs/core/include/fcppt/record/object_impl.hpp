//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_RECORD_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/record/element_tag_tuple.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_decl.hpp>
#include <fcppt/record/detail/all_initializers.hpp>
#include <fcppt/record/detail/element_at.hpp>
#include <fcppt/record/detail/label_is_same.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/find.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/types/args.hpp>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Types
>
fcppt::record::object<
	Types
>::object()
:
	elements_()
{
	static_assert(
		std::is_same<
			all_types,
			::brigand::list<>
		>::value,
		"record not empty"
	);
}

template<
	typename Types
>
fcppt::record::object<
	Types
>::object(
	fcppt::no_init const &
)
{
}

template<
	typename Types
>
fcppt::record::object<
	Types
>::object(
	fcppt::no_init &&
)
{
}

template<
	typename Types
>
template<
	typename ...Args
>
fcppt::record::object<
	Types
>::object(
	Args && ..._args
)
:
	elements_(
		[](
			auto &&... _args2
		){
			std::tuple<
				typename
				std::decay<
					Args
				>::type...
			> arguments(
				std::move(
					_args2
				)...
			);

			typedef
			::brigand::list<
				typename
				std::decay<
					Args
				>::type...
			>
			args_list;

			return
				fcppt::algorithm::vararg_map(
					fcppt::record::element_tag_tuple<
						this_type
					>{},
					[](
						auto &&... _args_inner
					)
					{
						return
							tuple{
								std::forward<
									decltype(
										_args_inner
									)
								>(
									_args_inner
								)...
							};
					},
					[
						&arguments
					](
						auto const _fcppt_element
					)
					{
						FCPPT_USE(
							_fcppt_element
						);

						typedef
						::brigand::index_if<
							args_list,
							::brigand::bind<
								fcppt::record::detail::label_is_same,
								::brigand::pin<
									fcppt::record::element_to_label<
										fcppt::tag_type<
											decltype(
												_fcppt_element
											)
										>
									>
								>,
								::brigand::_1
							>
						>
						index_type;

						return
							std::move(
								std::get<
									index_type::value
								>(
									arguments
								).value()
							);
					}
				);
		}(
			std::forward<
				Args
			>(
				_args
			)...
		)
	)
{
	static_assert(
		::brigand::size<
			all_types
		>::value
		==
		sizeof...(
			Args
		),
	 	"You have to provide the right amount of parameters"
	);

	static_assert(
		fcppt::record::detail::all_initializers<
			all_types,
			::brigand::list<
				Args...
			>
		>::value,
		"You have to initialize every element"
	);
}

template<
	typename Types
>
fcppt::record::object<
	Types
>::object(
	object const &
) = default;

template<
	typename Types
>
fcppt::record::object<
	Types
>::object(
	object &
) = default;

template<
	typename Types
>
fcppt::record::object<
	Types
>::object(
	object &&
) = default;

template<
	typename Types
>
fcppt::record::object<
	Types
> &
fcppt::record::object<
	Types
>::operator=(
	object const &
) = default;

template<
	typename Types
>
fcppt::record::object<
	Types
> &
fcppt::record::object<
	Types
>::operator=(
	object &&
) = default;

template<
	typename Types
>
fcppt::record::object<
	Types
>::~object()
{
}

template<
	typename Types
>
template<
	typename Label
>
void
fcppt::record::object<
	Types
>::set(
	fcppt::record::label_value_type<
		this_type,
		Label
	> const &_value
)
{
	fcppt::record::detail::element_at<
		all_types,
		Label
	>(
		elements_
	) =
		_value;
}

template<
	typename Types
>
template<
	typename Label
>
void
fcppt::record::object<
	Types
>::set(
	fcppt::record::label_value_type<
		this_type,
		Label
	> &&_value
)
{
	fcppt::record::detail::element_at<
		all_types,
		Label
	>(
		elements_
	) =
		std::move(
			_value
		);
}

template<
	typename Types
>
template<
	typename Label
>
fcppt::record::label_value_type<
	fcppt::record::object<
		Types
	>,
	Label
> const &
fcppt::record::object<
	Types
>::get() const
{
	return
		fcppt::record::detail::element_at<
			all_types,
			Label
		>(
			elements_
		);
}

template<
	typename Types
>
template<
	typename Label
>
fcppt::record::label_value_type<
	fcppt::record::object<
		Types
	>,
	Label
> &
fcppt::record::object<
	Types
>::get()
{
	return
		fcppt::record::detail::element_at<
			all_types,
			Label
		>(
			elements_
		);
}

template<
	typename Types
>
typename
fcppt::record::object<
	Types
>::tuple const &
fcppt::record::object<
	Types
>::impl() const
{
	return
		elements_;
}

#endif
