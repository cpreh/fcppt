//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STRONG_TYPEDEF_TAG_HPP_INCLUDED
#define FCPPT_DETAIL_STRONG_TYPEDEF_TAG_HPP_INCLUDED

#include <fcppt/is_strong_typedef.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename StrongTypedef
>
struct strong_typedef_tag
{
	static_assert(
		fcppt::is_strong_typedef<
			StrongTypedef
		>::value,
		"StrongTypedef must be an fcppt::strong_typedef"
	);

	typedef
	typename
	StrongTypedef::tag_type
	type;
};

}
}

#endif
