//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_TO_ARRAY_TYPE_TPL_HPP_INCLUDED
#define FCPPT_MATH_TO_ARRAY_TYPE_TPL_HPP_INCLUDED

#include <fcppt/math/detail/assert_static_storage.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Metafunction that returns the array type of an object with static storage

\ingroup fcpptmath
*/
template<
	typename Type
>
struct to_array_type_tpl
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

#endif
