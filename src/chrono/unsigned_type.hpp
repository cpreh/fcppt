//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_UNSIGNED_TYPE_HPP_INCLUDED
#define FCPPT_CHRONO_UNSIGNED_TYPE_HPP_INCLUDED

#include <fcppt/chrono/common_type.hpp>
#include <boost/type_traits/make_unsigned.hpp>
#include <ctime>

namespace fcppt
{
namespace chrono
{

namespace
{

template<
	typename Rep
>
struct unsigned_type
:
common_type<
	boost::make_unsigned<
		std::time_t
	>::type,
	Rep
>
{};

}

}
}

#endif
