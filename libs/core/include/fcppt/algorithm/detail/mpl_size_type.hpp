//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_MPL_SIZE_TYPE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MPL_SIZE_TYPE_HPP_INCLUDED

#include <fcppt/type_traits/is_brigand_sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/size.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Type,
	typename Test = void
>
struct mpl_size_type
{
	typedef
	void
	type;
};

template<
	typename Type
>
struct mpl_size_type<
	Type,
	std::enable_if_t<
		fcppt::type_traits::is_brigand_sequence<
			Type
		>::value
	>
>
{
	typedef
	typename
	::brigand::size<
		Type
	>::value_type
	type;
};

}
}
}

#endif
