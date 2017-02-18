//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_GET_EXN_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_GET_EXN_IMPL_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/variant/current_type_name.hpp>
#include <fcppt/variant/get_unsafe.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/invalid_get.hpp>
#include <fcppt/variant/types_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Ret,
	typename Variant
>
inline
Ret &
get_exn_impl(
	Variant &_variant
)
{
	typedef
	typename
	std::remove_const<
		Ret
	>::type
	return_type;

	if(
		!fcppt::variant::holds_type<
			return_type
		>(
			_variant
		)
	)
		throw
			fcppt::variant::invalid_get{
				FCPPT_TEXT("Invalid get of type \"")
				+
				fcppt::type_name_from_info(
					typeid(
						return_type
					)
				)
				+
				FCPPT_TEXT("\" from variant with types \"")
				+
				fcppt::variant::types_string<
					Variant
				>()
				+
				FCPPT_TEXT("\". Current type was \"")
				+
				fcppt::variant::current_type_name(
					_variant
				)
				+
				FCPPT_TEXT("\".")
			};

	return
		fcppt::variant::get_unsafe<
			return_type
		>(
			_variant
		);
}

}
}
}

#endif
