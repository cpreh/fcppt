//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_APPEND_HPP_INCLUDED
#define FCPPT_MPL_APPEND_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/push_back.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Appends two MPL sequences

\ingroup fcpptmpl

Appends \a Sequence2 to \a Sequence1

\snippet mpl/various.cpp mpl_append

\tparam Sequence1 The MPL sequence to append to

\tparam Sequence2 The MPL sequence to append
*/
template<
	typename Sequence1,
	typename Sequence2
>
struct append
:
boost::mpl::fold<
	Sequence2,
	Sequence1,
	boost::mpl::push_back<
		boost::mpl::_1,
		boost::mpl::_2
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
