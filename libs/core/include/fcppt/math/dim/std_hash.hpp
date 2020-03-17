//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_STD_HASH_HPP_INCLUDED
#define FCPPT_MATH_DIM_STD_HASH_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/hash_impl.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
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
	fcppt::math::size_type N,
	typename S
>
struct hash<
	fcppt::math::dim::object<
		T,
		N,
		S
	>
>
{
	using
	type
	=
	fcppt::math::dim::object<
		T,
		N,
		S
	>;

	std::size_t
	operator()(
		type const &_value
	) const
	{
		return
			fcppt::math::detail::hash<
				type
			>()(
				_value
			);
	}
};

FCPPT_PP_POP_WARNING

}

#endif
