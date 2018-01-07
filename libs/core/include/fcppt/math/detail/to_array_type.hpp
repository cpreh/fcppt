//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_TO_ARRAY_TYPE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_TO_ARRAY_TYPE_HPP_INCLUDED

#include <fcppt/math/detail/assert_static_storage.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Type
>
struct to_array_type
{
	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		typename
		Type::storage_type
	);

	typedef
	typename
	Type::storage_type::array_type
	type;
};

}
}
}

#endif
