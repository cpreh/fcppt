//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED
#define FCPPT_MPL_SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED

#include <fcppt/mpl/set_difference.hpp>
#include <fcppt/mpl/set_union.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief The symmetric difference of two sets

\ingroup fcpptmpl

The result contains every element that is either in \a Set1 or in \a Set2, but
not in both.

\tparam Set1 Must be an MPL set
\tparam Set2 Must be an MPL set
*/
template<
	typename Set1,
	typename Set2
>
struct set_symmetric_difference
:
fcppt::mpl::set_union<
	typename
	fcppt::mpl::set_difference<
		Set1,
		Set2
	>::type,
	typename
	fcppt::mpl::set_difference<
		Set2,
		Set1
	>::type
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
