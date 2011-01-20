//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_MOVABLE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_MOVABLE_HPP_INCLUDED

#include <fcppt/unique_ptr_fwd.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace type_traits
{

template<
	typename T
>
struct is_movable
:
boost::false_type
{};

template<
	typename T,
	template<
		typename
	> class Deleter
>
struct is_movable<
	fcppt::unique_ptr<
		T,
		Deleter
	>
>
:
boost::true_type
{};

}
}

#endif
