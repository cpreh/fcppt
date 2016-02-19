//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RUNTIME_ENUM_HPP_INCLUDED
#define FCPPT_RUNTIME_ENUM_HPP_INCLUDED

#include <fcppt/absurd.hpp>
#include <fcppt/decltype_sink.hpp>
#include <fcppt/enum_max_value.hpp>
#include <fcppt/enum_size.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/static_cast_fun.hpp>
#include <fcppt/mpl/integral_cast.hpp>
#include <fcppt/mpl/runtime_index.hpp>
#include <fcppt/config/external_begin.hpp>
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
decltype(
	auto
)
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
			fcppt::cast::enum_to_int<
				int_type
			>(
				_enum
			),
			[
				&_function
			](
				auto const _fcppt_index
			)
			{
				return
					_function(
						fcppt::mpl::integral_cast<
							Enum,
							fcppt::cast::static_cast_fun,
							FCPPT_DECLTYPE_SINK(
								_fcppt_index
							)
						>{}
					);
			},
			&fcppt::absurd<
				decltype(
					_function(
						fcppt::enum_max_value<
							Enum
						>{}
					)
				)
			>
		);

}

}

#endif
