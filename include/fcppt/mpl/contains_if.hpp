//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_CONTAINS_IF_HPP_INCLUDED
#define FCPPT_MPL_CONTAINS_IF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_same.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace mpl
{

/**
\brief Checks if a sequence contains an element matching a predicate

\ingroup fcpptmpl

Checks if \a Sequence contains an element matching \a Predicate.

\snippet mpl/various.cpp mpl_contains_if

\tparam Sequence An MPL sequence

\tparam Predicate A unary lambda expression evaluating to a truth valued
integral constant

\return A truth valued integral constant
*/
template<
	typename Sequence,
	typename Predicate
>
struct contains_if
:
boost::mpl::not_<
	boost::is_same<
		typename boost::mpl::find_if<
			Sequence,
			Predicate
		>::type,
		typename boost::mpl::end<
			Sequence
		>::type
	>
>
{
};

}
}

#endif
