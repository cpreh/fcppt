//          Copyright Carl Philipp Reh 2009 - 2020.
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
	std::enable_if_t<
		std::is_enum_v<
			Enum
		>
	>
>
{
	using
	undecorated_type
	=
	std::underlying_type_t<
		Enum
	>;

	static
	inline
	Enum
	decorate(
		undecorated_type const _value
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
	undecorated_type
	undecorate(
		Enum const _value
	)
	{
		return
			fcppt::cast::enum_to_int<
				undecorated_type
			>(
				_value
			);
	}
};

}
}

#endif
