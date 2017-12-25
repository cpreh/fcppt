//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_SEQUENCE_TO_TUPLE_HPP_INCLUDED
#define FCPPT_MPL_SEQUENCE_TO_TUPLE_HPP_INCLUDED

#include <fcppt/mpl/detail/fold_tuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Converts an MPL sequence to a <code>std::tuple</code>.

\ingroup fcpptmpl
*/
template<
	typename Sequence
>
using
sequence_to_tuple
=
boost::mpl::fold<
	Sequence,
	std::tuple<>,
	fcppt::mpl::detail::fold_tuple<
		boost::mpl::_2,
		boost::mpl::_1
	>
>;

}
}

#endif
