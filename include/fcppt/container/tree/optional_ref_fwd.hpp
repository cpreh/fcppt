//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OPTIONAL_REF_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OPTIONAL_REF_FWD_HPP_INCLUDED

#include <fcppt/optional/reference_fwd.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

template<
	typename Tree
>
using optional_ref
=
fcppt::optional::reference<
	Tree
>;

}
}
}

#endif
