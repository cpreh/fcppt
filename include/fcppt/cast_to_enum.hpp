//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TO_ENUM_HPP_INCLUDED
#define FCPPT_CAST_TO_ENUM_HPP_INCLUDED

#include <fcppt/enum_size.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Cast an unsigned value to an enum

\ingroup fcpptenum

Casts the unsigned value \a _value to \a Enum, throwing an exception if the
value is out of range.

\param _value The value to cast from

\tparam Enum Must be an enum type

\tparam Value Must be an unsigned type

\see fcppt::enum_size

\throws fcppt::exception if \a _value is greater or equal to the enum's max
size

\return The casted value if it fits into the enum's range
*/
template<
	typename Enum,
	typename Value
>
typename boost::enable_if<
	boost::mpl::and_<
		std::is_unsigned<
			Value
		>,
		std::is_enum<
			Enum
		>
	>,
	Enum
>::type
cast_to_enum(
	Value const &_value
)
{
	if(
		fcppt::cast::size<
			typename
			fcppt::enum_size_type<
				Enum
			>::type
		>(
			_value
		)
		>=
		fcppt::enum_size<
			Enum
		>::value
	)
		throw fcppt::exception(
			FCPPT_TEXT("Tried to cast value ")
			+
			fcppt::insert_to_fcppt_string(
				fcppt::cast::size<
					unsigned long long
				>(
					_value
				)
			)
			+
			FCPPT_TEXT(" to an enum of type ")
			+
			fcppt::type_name(
				typeid(
					Enum
				)
			)
			+
			FCPPT_TEXT(" which doesn't fit into the enum's range!")
		);

	return
		static_cast<
			Enum
		>(
			_value
		);
}

}

#endif

