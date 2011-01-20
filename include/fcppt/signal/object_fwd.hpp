//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_OBJECT_FWD_HPP_INCLUDED
#define FCPPT_SIGNAL_OBJECT_FWD_HPP_INCLUDED

#include <fcppt/signal/base_fwd.hpp>

namespace fcppt
{
namespace signal
{

template<
	typename T,
	template<
		typename
	> class Base = signal::base,
	typename Enable = void
>
class object;

}
}

#endif
