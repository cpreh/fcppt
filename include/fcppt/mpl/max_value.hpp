//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_MAX_VALUE_HPP_INCLUDED
#define FCPPT_MPL_MAX_VALUE_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/max_element.hpp>
#include <boost/mpl/transform.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Calculates the maximum value in a sequence using a metafunction

\ingroup fcpptmpl

Calculates the maximum value in \a Sequence according to \a MetaFunction. \a
MetaFunction will be invoked on every type in \a Sequence and the maximum value
of them will be returned.

\snippet mpl/various.cpp mpl_max_value

\tparam Sequence An MPL sequence

\tparam MetaFunction A metafunction transforming every type in the sequence
into an MPL integral constant
*/
template<
	typename Sequence,
	typename MetaFunction
>
struct max_value
:
boost::mpl::deref<
	typename boost::mpl::max_element<
		typename boost::mpl::transform<
			Sequence,
			MetaFunction
		>::type
	>::type
>::type
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
