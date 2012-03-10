//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IS_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_IS_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename T
>
struct is_strong_typedef
:
boost::false_type
{
};

template<
	typename Type,
	typename Tag
>
struct is_strong_typedef<
	fcppt::strong_typedef<
		Type,
		Tag
	>
>
:
boost::true_type
{
};


}

#endif
