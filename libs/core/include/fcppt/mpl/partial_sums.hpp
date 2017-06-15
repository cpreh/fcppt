//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_PARTIAL_SUMS_HPP_INCLUDED
#define FCPPT_MPL_PARTIAL_SUMS_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Calculates a new sequence that consists of the sums of the old sequence

\ingroup fcpptmpl

For the integral constantsn (c_1, ..., c_n) in \a Sequence, the resulting
sequence will consist of the values (0, c_1, c_1 + c_2, ..., c_1 + ... c_n)

\snippet mpl/various.cpp mpl_partial_sums

\tparam Sequence An MPL sequence of integral constant types

\tparam IntType The integer type to use for the first zero
*/
template<
	typename Sequence,
	// mpl::plus<> converts its operands, so int is most conservative
	typename IntType = int
>
struct partial_sums
:
boost::mpl::fold<
	Sequence,
	boost::mpl::vector_c<
		IntType,
		0
	>,
	boost::mpl::push_back<
		boost::mpl::_1,
		boost::mpl::plus<
			boost::mpl::back<
				boost::mpl::_1
			>,
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
