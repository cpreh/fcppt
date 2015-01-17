//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_IS_OBJECT_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_IS_OBJECT_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>
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
namespace tree
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief A meta function testing if the given type is really a tree object
\ingroup fcpptcontainertree
*/
template<
	typename T
>
struct is_object
:
std::false_type
{
};

/**
\brief A meta function testing if the given type is really a tree object
\ingroup fcpptcontainertree
*/
template<
	typename T
>
struct is_object<
	fcppt::container::tree::object<
		T
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
