//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_ENUM_HPP_INCLUDED
#define FCPPT_TYPE_ISO_ENUM_HPP_INCLUDED

#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/type_iso/transform_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_iso
{

template<
	typename Enum
>
struct transform<
	Enum,
	typename
	std::enable_if<
		std::is_enum<
			Enum
		>::value
	>::type
>
{
	typedef
	typename
	std::underlying_type<
		Enum
	>::type
	base_type;

	static
	inline
	Enum
	decorated_value(
		base_type const _value
	)
	{
		return
			fcppt::cast::int_to_enum<
				Enum
			>(
				_value
			);
	}

	static
	inline
	base_type
	base_value(
		Enum const _value
	)
	{
		return
			fcppt::cast::enum_to_int<
				base_type
			>(
				_value
			);
	}
};

}
}

#endif
