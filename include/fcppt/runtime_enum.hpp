//          Copyright Carl Philipp Reh 2009 - 2014.
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
boost::enable_if<
	std::is_enum<
		Enum
	>,
	typename
	Function::result_type
>::type
runtime_enum(
	Enum const _enum,
	Function const &_function
)
{
	typedef
	typename
	std::make_unsigned<
		typename
		std::underlying_type<
			Enum
		>::type
	>::type
	int_type;

	return
		fcppt::mpl::runtime_index<
			fcppt::mpl::integral_cast<
				int_type,
				fcppt::enum_size<
					Enum
				>
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
