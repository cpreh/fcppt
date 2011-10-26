//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REF_HPP_INCLUDED
#define FCPPT_REF_HPP_INCLUDED

#include <fcppt/reference_wrapper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ref.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

/// Wrapper around boost::ref for now
/**
 * std::tr1::ref under VC++ has issues,
 * in order to provide a single refactoring point,
 * fcppt::ref wraps boost::ref currently
*/
template<
	typename T
>
fcppt::reference_wrapper<
	T
> const
ref(
	T &_ref
)
{
	return
		boost::ref(
			_ref
		);
}

}

#endif
