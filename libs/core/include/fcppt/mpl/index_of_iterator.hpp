//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INDEX_OF_ITERATOR_HPP_INCLUDED
#define FCPPT_MPL_INDEX_OF_ITERATOR_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/distance.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Calculates the index of an iterator in a sequence.

\ingroup fcpptmpl

\tparam Sequence Must be an MPL sequence.

\tparam Iterator The iterator to calculate the index of. Must point to \a Sequence.
*/
template<
	typename Sequence,
	typename Iterator
>
struct index_of_iterator
:
boost::mpl::distance<
	typename
	boost::mpl::begin<
		Sequence
	>::type,
	Iterator
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
