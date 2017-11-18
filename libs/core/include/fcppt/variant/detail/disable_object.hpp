//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_DISABLE_OBJECT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_DISABLE_OBJECT_HPP_INCLUDED

#include <fcppt/type_traits/remove_cv_ref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/or.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename U,
	typename Variant
>
using disable_object
=
typename
std::enable_if<
	!boost::mpl::or_<
		std::is_const<
			typename
			std::remove_reference<
				U
			>::type
		>,
		std::is_same<
			typename
			fcppt::type_traits::remove_cv_ref<
				U
			>::type,
			Variant
		>
	>::value,
	Variant
>::type;

}
}
}

#endif
