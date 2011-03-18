//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_WRAPPER_HPP_INCLUDED
#define FCPPT_REFERENCE_WRAPPER_HPP_INCLUDED

#include <fcppt/detail/use_boost_reference.hpp>
#ifdef FCPPT_DETAIL_USE_BOOST_REFERENCE
#include <boost/ref.hpp>
#else
#include <fcppt/tr1/functional.hpp>
#endif

namespace fcppt
{

#ifdef FCPPT_DETAIL_USE_BOOST_REFERENCE
using boost::reference_wrapper;
#else
using std::tr1::reference_wrapper;
#endif

}

#endif
