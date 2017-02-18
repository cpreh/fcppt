//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INDEX_OF_HPP_INCLUDED
#define FCPPT_MPL_INDEX_OF_HPP_INCLUDED

#include <fcppt/mpl/index_of_iterator.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/contains.hpp>
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

\tparam Sequence Must be an MPL sequence.

\tparam Element The element to calculate the index of. Must be an element of \a Sequence.
*/
template<
	typename Sequence,
	typename Element
>
struct index_of
:
fcppt::mpl::index_of_iterator<
	Sequence,
	typename
	boost::mpl::find<
		Sequence,
		Element
	>::type
>
{
	static_assert(
		boost::mpl::contains<
			Sequence,
			Element
		>::value,
		"mpl::index_of<S,E> used but S doesn't contain E"
	);
};

FCPPT_PP_POP_WARNING

}
}

#endif
