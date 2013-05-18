//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DIM_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DIM_FWD_HPP_INCLUDED

#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename SizeType,
	fcppt::container::grid::size_type N
>
struct dim
:
fcppt::math::dim::static_<
	SizeType,
	N
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
