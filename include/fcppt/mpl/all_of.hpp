//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_ALL_OF_HPP_INCLUDED
#define FCPPT_MPL_ALL_OF_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/bind.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/placeholders.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Checks if a predicate is true for all elements of an MPL sequence

\ingroup fcpptmpl

For every element in \a Sequence, it is checked whether \a Predicate holds

\tparam Sequence The MPL sequence to check

\tparam Predicate A unary MPL predicate to apply to every element
*/
template<
	typename Sequence,
	typename Predicate
>
struct all_of
:
boost::mpl::fold<
	Sequence,
	boost::mpl::true_,
	boost::mpl::and_<
		boost::mpl::_1,
		boost::mpl::bind<
			typename boost::mpl::lambda<
				Predicate
			>::type,
			boost::mpl::_2
		>
	>
>::type
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
