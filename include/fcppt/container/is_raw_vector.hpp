//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_IS_RAW_VECTOR_HPP_INCLUDED
#define FCPPT_CONTAINER_IS_RAW_VECTOR_HPP_INCLUDED

#include <fcppt/container/raw_vector_fwd.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace container
{

template<
	typename T
>
struct is_raw_vector
:
boost::false_type
{};

template<
	typename T,
	typename A
>
struct is_raw_vector<
	fcppt::container::raw_vector<
		T,
		A
	>
>
:
boost::true_type
{};

}
}

#endif
