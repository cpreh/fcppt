//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_SET_UNION_HPP_INCLUDED
#define FCPPT_MPL_SET_UNION_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/inserter.hpp>
#include <boost/mpl/placeholders.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief The union of two sets

\ingroup fcpptmpl

The result contains every element that is in \a Set1 or in \a Set2.

\tparam Set1 Must be an MPL set
\tparam Set2 Must be an MPL set
*/
template<
	typename Set1,
	typename Set2
>
struct set_union
:
boost::mpl::copy<
	Set2,
	boost::mpl::inserter<
		Set1,
		boost::mpl::insert<
			boost::mpl::_1,
			boost::mpl::_2
		>
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif