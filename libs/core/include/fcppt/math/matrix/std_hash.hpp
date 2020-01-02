//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STD_HASH_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STD_HASH_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/to_array.hpp>
#include <fcppt/math/to_array_type.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/range/hash_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace std
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wmismatched-tags)

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
struct hash<
	fcppt::math::matrix::object<
		T,
		R,
		C,
		S
	>
>
{
	typedef
	fcppt::math::matrix::object<
		T,
		R,
		C,
		S
	> type;

	std::size_t
	operator()(
		type const &_value
	) const
	{
		return
			fcppt::range::hash<
				fcppt::math::to_array_type<
					type
				>
			>{}(
				fcppt::math::to_array(
					_value
				)
			);
	}
};

FCPPT_PP_POP_WARNING

}

#endif
