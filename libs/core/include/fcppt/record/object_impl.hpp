//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_RECORD_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/mpl/index_of_iterator.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_decl.hpp>
#include <fcppt/record/detail/all_initializers.hpp>
#include <fcppt/record/detail/element_at.hpp>
#include <fcppt/record/detail/label_is_same.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector.hpp>
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
		boost::mpl::empty<
			all_types
		>::value,
		"record not empty"
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

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

FCPPT_PP_POP_WARNING


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

			return
				fcppt::algorithm::vararg_map(
					all_types{},
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
						decltype(
							_fcppt_element
						)
						role;

						typedef
						boost::mpl::vector<
							typename
							std::decay<
								Args
							>::type...
						>
						vector_type;

						typedef
						fcppt::mpl::index_of_iterator<
							vector_type,
							typename
							boost::mpl::find_if<
								vector_type,
								fcppt::record::detail::label_is_same<
									fcppt::record::element_to_label<
										role
									>,
									boost::mpl::_1
								>
							>::type
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
		boost::mpl::size<
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
			boost::mpl::vector<
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
