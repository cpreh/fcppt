//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_COPY_HPP_INCLUDED
#define FCPPT_MPL_COPY_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Copies an MPL sequence into an <code>mpl::vector</code>.

\ingroup fcpptmpl

\tparam Source Must be an MPL sequence
*/
template<
	typename Source
>
struct copy
:
boost::mpl::fold<
	Source,
	boost::mpl::vector0<>,
	boost::mpl::push_back<
		boost::mpl::_,
		boost::mpl::_
	>
>
{
};

}
}

#endif
