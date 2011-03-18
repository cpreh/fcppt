//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REF_HPP_INCLUDED
#define FCPPT_REF_HPP_INCLUDED

#include <fcppt/detail/use_boost_reference.hpp>
#include <fcppt/reference_wrapper.hpp>
#ifdef FCPPT_DETAIL_USE_BOOST_REFERENCE
#include <boost/ref.hpp>
#else
#include <fcppt/tr1/functional.hpp>
#endif

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
#ifdef FCPPT_DETAIL_USE_BOOST_REFERENCE
		boost::ref(
#else
		std::tr1::ref(
#endif
			_ref
		);
}

}

#endif
