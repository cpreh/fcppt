//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_IS_OBJECT_HPP_INCLUDED
#define FCPPT_RATIO_IS_OBJECT_HPP_INCLUDED

#include <fcppt/ratio/int_type.hpp>
#include <fcppt/ratio/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace ratio
{

template<
	typename T
>
struct is_object
:
boost::false_type
{};

template<
	int_type N,
	int_type D
>
struct is_object<
	object<
		N,
		D
	>
>
:
boost::true_type
{};

}
}

#endif
