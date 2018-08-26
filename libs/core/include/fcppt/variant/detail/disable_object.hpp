//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_DISABLE_OBJECT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_DISABLE_OBJECT_HPP_INCLUDED

#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
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
std::enable_if_t<
	!(
		std::is_const<
			std::remove_reference_t<
				U
			>
		>::value
		||
		std::is_same<
			fcppt::type_traits::remove_cv_ref_t<
				U
			>,
			Variant
		>::value
	),
	Variant
>;

}
}
}

#endif
