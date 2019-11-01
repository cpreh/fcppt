//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_RECORD_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/record/element_tag_tuple.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_decl.hpp>
#include <fcppt/record/detail/all_initializers.hpp>
#include <fcppt/record/detail/element_at.hpp>
#include <fcppt/record/detail/init_ctor.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/list/empty.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Types
>
fcppt::record::object<
	Types
>::object()
:
	elements_{}
{
	static_assert(
		::metal::empty<
			all_types
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
template<
	typename ...Args,
	typename
>
fcppt::record::object<
	Types
>::object(
	Args && ..._args
)
:
	elements_{
		fcppt::record::detail::init_ctor<
			tuple,
			fcppt::record::element_tag_tuple<
				this_type
			>,
			Args...
		>(
			std::forward<
				Args
			>(
				_args
			)...
		)
	}
{
	static_assert(
		::metal::size<
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
			::metal::list<
				Args...
			>
		>::value,
		"You have to initialize every element"
	);
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
