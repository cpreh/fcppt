//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_DETAIL_IS_RAW_POINTER_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_DETAIL_IS_RAW_POINTER_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{
namespace detail
{

template<
	typename Type
>
struct is_raw_pointer
{
	static_assert(
		std::is_pointer<
			Type
		>::value,
		"Type must be a pointer"
	);

	typedef
	std::remove_cv_t<
		std::remove_pointer_t<
			Type
		>
	>
	base_type;

	typedef
	std::integral_constant<
		bool,
		std::is_same<
			base_type,
			char
		>::value
		||
		std::is_same<
			base_type,
			unsigned char
		>::value
	>
	type;
};

}
}
}

#endif
