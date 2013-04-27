//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_SIZE_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_SIZE_HPP_INCLUDED

#include <fcppt/container/detail/array_size.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace container
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Defines the size of an array

\ingroup fcpptcontainer

Defines the size of \a Array by deriving from an integral constant.

\tparam Array Must be a std::array
*/
template<
	typename Array
>
struct array_size
:
fcppt::container::detail::array_size<
	Array
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
