//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_CHOOSE_REFERENCE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_CHOOSE_REFERENCE_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Container
>
struct choose_reference
:
std::conditional<
	std::is_const<
		Container
	>::value,
	typename Container::const_reference,
	typename Container::reference
>
{
};

FCPPT_PP_POP_WARNING

}
}
}
}

#endif
