//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_STD_HASH_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_STD_HASH_HPP_INCLUDED

#include <fcppt/container/bitfield/hash_impl.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp>
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
	typename ElementType,
	typename NumElements,
	typename InternalType
>
struct hash<
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	>
>
{
	typedef
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	>
	type;

	std::size_t
	operator()(
		type const &_value
	) const
	{
		return
			fcppt::container::bitfield::hash<
				type
			>()(
				_value
			);
	}
};

#if defined(FCPPT_CONFIG_CLANG_COMPILER)
FCPPT_PP_POP_WARNING
#endif

}

#endif
