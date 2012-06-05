//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INDEX_OF_HPP_INCLUDED
#define FCPPT_MPL_INDEX_OF_HPP_INCLUDED

#include <fcppt/static_assert_statement.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/find.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Calculates the index of an element in a sequence

\ingroup fcpptmpl

Calculates the index of \a Element in \a Sequence.

\snippet mpl/various.cpp mpl_index_of

\tparam Sequence The MPL sequence

\tparam Element The element to calculate the index of

\return The index of the element or an error if the element was not found
*/
template<
	typename Sequence,
	typename Element
>
struct index_of
:
boost::mpl::distance<
	typename boost::mpl::begin<
		Sequence
	>::type,
	typename boost::mpl::find<
		Sequence,
		Element
	>::type
>
{
	FCPPT_STATIC_ASSERT_STATEMENT((
		boost::mpl::contains<
			Sequence,
			Element
		>::value
	));
};

FCPPT_PP_POP_WARNING

}
}

#endif
