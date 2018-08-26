//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_DETAIL_ALL_OF_IMPL_HPP_INCLUDED
#define FCPPT_BRIGAND_DETAIL_ALL_OF_IMPL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/logical/and.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{
namespace detail
{

template<
	typename Sequence,
	typename Predicate,
	typename... Ts
>
struct all_of_impl;

template<
	template <class...> class Sequence,
	typename Predicate,
	typename... Ts
>
struct all_of_impl<
	Sequence<
		Ts...
	>,
	Predicate
>
:
::brigand::and_<
	std::true_type,
	::brigand::apply<
		Predicate,
		Ts
	>...
>
{
};

}
}
}

#endif
