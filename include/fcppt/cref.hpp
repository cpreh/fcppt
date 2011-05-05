//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CREF_HPP_INCLUDED
#define FCPPT_CREF_HPP_INCLUDED

#include <fcppt/reference_wrapper.hpp>
#include <boost/ref.hpp>

namespace fcppt
{

/// Wrapper around boost::cref for now
/**
 * std::tr1::cref under VC++ has issues,
 * in order to provide a single refactoring point,
 * fcppt::cref wraps boost::cref currently
*/
template<
	typename T
>
fcppt::reference_wrapper<
	T const
> const
cref(
	T const &_ref
)
{
	return
		boost::cref(
			_ref
		);
}

}

#endif
