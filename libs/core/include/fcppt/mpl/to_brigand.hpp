//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_TO_BRIGAND_HPP_INCLUDED
#define FCPPT_MPL_TO_BRIGAND_HPP_INCLUDED

#include <fcppt/mpl/detail/to_brigand.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Converts and MPL sequence to a brigand::list.

\ingroup fcpptmpl
*/
template<
	typename Seq
>
using
to_brigand
=
typename
fcppt::mpl::detail::to_brigand<
	typename
	boost::mpl::begin<
		Seq
	>::type,
	typename
	boost::mpl::end<
		Seq
	>::type,
	::brigand::list<>
>::type;

}
}

#endif
