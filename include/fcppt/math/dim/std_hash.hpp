//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_STD_HASH_HPP_INCLUDED
#define FCPPT_MATH_DIM_STD_HASH_HPP_INCLUDED

#include <fcppt/range_hash_impl.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/config/compiler.hpp>
#if defined(FCPPT_CONFIG_CLANG_COMPILER)
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace std
{

#if defined(FCPPT_CONFIG_CLANG_COMPILER)
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wmismatched-tags)
#endif

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
	typedef
	fcppt::math::dim::object<
		T,
		N,
		S
	> type;

	std::size_t
	operator()(
		type const &_value
	) const
	{
		return
			fcppt::range_hash<
				typename
				type::storage_type
			>()(
				_value.storage()
			);
	}
};

#if defined(FCPPT_CONFIG_CLANG_COMPILER)
FCPPT_PP_POP_WARNING
#endif

}

#endif
