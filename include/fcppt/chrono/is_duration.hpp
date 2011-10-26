//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_IS_DURATION_HPP_INCLUDED
#define FCPPT_CHRONO_IS_DURATION_HPP_INCLUDED

#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace chrono
{

template<
	typename T
>
struct is_duration
:
boost::false_type
{};

template<
	typename Rep,
	typename Period
>
struct is_duration<
	duration<
		Rep,
		Period
	>
>
:
boost::true_type
{};

}
}

#endif
