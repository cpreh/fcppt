//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_ELEMENT_BITS_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_ELEMENT_BITS_HPP_INCLUDED

#include <fcppt/mpl/integral_cast.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename SizeType,
	typename Type
>
struct element_bits
:
fcppt::mpl::integral_cast<
	SizeType,
	std::integral_constant<
		int,
		std::numeric_limits<
			Type
		>::digits
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}
}
}

#endif
