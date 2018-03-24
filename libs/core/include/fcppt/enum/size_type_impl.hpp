//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_SIZE_TYPE_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_SIZE_TYPE_IMPL_HPP_INCLUDED

#include <fcppt/enum/size_type_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace enum_
{

/**
\brief Implementation of \link fcppt::enum_::size_type\endlink.

\ingroup fcpptenum

\tparam Type Must be an enum type
*/
template<
	typename Type
>
struct size_type_impl
{
	static_assert(
		std::is_enum<
			Type
		>::value,
		"Type must be an enum type"
	);

	typedef
	std::make_unsigned_t<
		std::underlying_type_t<
			Type
		>
	>
	type;
};

}
}

#endif
