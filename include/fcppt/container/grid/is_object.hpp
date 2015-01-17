//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_IS_OBJECT_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_IS_OBJECT_HPP_INCLUDED

#include <fcppt/container/grid/object_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type
>
struct is_object
:
std::false_type
{
};

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
struct is_object<
	fcppt::container::grid::object<
		T,
		N,
		A
	>
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
