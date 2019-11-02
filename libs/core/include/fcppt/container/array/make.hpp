//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_MAKE_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_MAKE_HPP_INCLUDED

#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/always.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/trait.hpp>
#include <metal/list/all_of.hpp>
#include <metal/list/front.hpp>
#include <metal/list/list.hpp>
#include <array>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace array
{

/**
\brief Make an array out of a parameter pack.

\ingroup fcpptcontainerarray

Let \a _args be <code>(a_1,...,a_n)</code>. All elements of \a _args must be of
the same type <code>T</code>. The result is
<code>std::array<T,n>{a_1,...,a_n}</code>.

\tparam Args A parameter pack <code>t_1,...,t_n</code> such that
<code>remove_cv_ref<t_1> = ... = remove_cv_ref<t_n></code>.
*/
template<
	typename... Args
>
inline
std::array<
	::metal::front<
		::metal::list<
			fcppt::type_traits::remove_cv_ref_t<
				Args
			>...
		>
	>,
	sizeof...(Args)
>
make(
	Args &&... _args
)
{
	typedef
	::metal::list<
		fcppt::type_traits::remove_cv_ref_t<
			Args
		>...
	>
	decayed_args;

	typedef
	::metal::front<
		decayed_args
	>
	first_type;

	typedef
	std::array<
		first_type,
		sizeof...(Args)
	>
	result_type;

	static_assert(
		::metal::all_of<
			decayed_args,
			::metal::bind<
				::metal::trait<
					std::is_same
				>,
				::metal::always<
					first_type
				>,
				::metal::_1
			>
		>::value,
		"All types of array::make must be the same"
	);

	return
		result_type{{
			std::forward<
				Args
			>(
				_args
			)...
		}};
}

}
}
}

#endif
