//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_TREAT_AS_FLOATING_POINT_HPP_INCLUDED
#define FCPPT_CHRONO_TREAT_AS_FLOATING_POINT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace chrono
{

template<
	typename Rep
>
struct treat_as_floating_point
:
boost::is_floating_point<
	Rep
>
{};

}
}

#endif
