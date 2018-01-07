//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_MAKE_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_MAKE_ARRAY_HPP_INCLUDED

#include <fcppt/brigand/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/front.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <array>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Make an array out of a parameter pack.

Let \a _args be <code>(a_1,...,a_n)</code>. All elements of \a _args must be of
the same type <code>T</code>. The result is
<code>std::array<T,n>{a_1,...,a_n}</code>.

\tparam Args A parameter pack <code>t_1,...,t_n</code> such that
<code>std::decay<t_1> = ... = std::decay<t_n></code>.
*/
template<
	typename... Args
>
inline
std::array<
	::brigand::front<
		::brigand::list<
			typename
			std::decay<
				Args
			>::type...
		>
	>,
	sizeof...(Args)
>
make_array(
	Args &&... _args
)
{
	typedef
	::brigand::list<
		typename
		std::decay<
			Args
		>::type...
	>
	decayed_args;

	typedef
	::brigand::front<
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
		fcppt::brigand::all_of<
			decayed_args,
			::brigand::bind<
				std::is_same,
				::brigand::pin<
					first_type
				>,
				::brigand::_1
			>
		>::value,
		"All types of make_array must be the same"
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

#endif
