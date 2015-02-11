//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RUNTIME_ENUM_HPP_INCLUDED
#define FCPPT_RUNTIME_ENUM_HPP_INCLUDED

#include <fcppt/enum_size.hpp>
#include <fcppt/detail/runtime_enum_function.hpp>
#include <fcppt/mpl/integral_cast.hpp>
#include <fcppt/mpl/runtime_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts a runtime enum value into a compile time one, passing it to a
function

\ingroup fcpptenum
*/
template<
	typename Enum,
	typename Function
>
inline
typename
Function::result_type
runtime_enum(
	Enum const _enum,
	Function const &_function
)
{
	static_assert(
		std::is_enum<
			Enum
		>::value,
		"runtime_enum can only be used on enumeration types"
	);

	typedef
	typename
	fcppt::enum_size_type<
		Enum
	>::type
	int_type;

	return
		fcppt::mpl::runtime_index<
			fcppt::enum_size<
				Enum
			>
		>(
			static_cast<
				int_type
			>(
				_enum
			),
			fcppt::detail::runtime_enum_function<
				Enum,
				Function
			>(
				_function
			),
			[]
			()
			->
			typename
			Function::result_type
			{
				std::terminate();
			}
		);

}

}

#endif
