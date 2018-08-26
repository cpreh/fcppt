//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_FROM_INT_EXN_HPP_INCLUDED
#define FCPPT_ENUM_FROM_INT_EXN_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/enum/from_int.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace enum_
{

/**
\brief Cast an unsigned value to an enum

\ingroup fcpptenum

Casts the unsigned value \a _value to \a Enum, throwing an exception if the
value is out of range.

\param _value The value to cast from

\tparam Enum Must be an enum type

\tparam Value Must be an unsigned type

\throws fcppt::exception if \a _value is greater or equal to the enum's max
size

\return The casted value if it fits into the enum's range
*/
template<
	typename Enum,
	typename Value
>
Enum
from_int_exn(
	Value const &_value
)
{
	static_assert(
		std::is_unsigned<
			Value
		>::value
		&&
		std::is_enum<
			Enum
		>::value,
		"cast_to_enum can only cast from unsigned types to enumeration types"
	);

	return
		fcppt::optional::to_exception(
			fcppt::enum_::from_int<
				Enum
			>(
				_value
			),
			[
				_value
			]{
				return
					fcppt::exception{
						FCPPT_TEXT("Tried to cast value ")
						+
						fcppt::output_to_fcppt_string(
							fcppt::cast::size<
								unsigned long long
							>(
								_value
							)
						)
						+
						FCPPT_TEXT(" to an enum of type ")
						+
						fcppt::type_name_from_info(
							typeid(
								Enum
							)
						)
						+
						FCPPT_TEXT(" which doesn't fit into the enum's range!")
					};
			}
		);
}

}
}

#endif
