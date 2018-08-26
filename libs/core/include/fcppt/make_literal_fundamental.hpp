//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_LITERAL_FUNDAMENTAL_HPP_INCLUDED
#define FCPPT_MAKE_LITERAL_FUNDAMENTAL_HPP_INCLUDED

#include <fcppt/check_literal_conversion.hpp>
#include <fcppt/make_literal_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\ingroup fcpptliteral
*/
template<
	typename Type
>
struct make_literal<
	Type,
	std::enable_if_t<
		std::is_arithmetic<
			Type
		>::value
	>
>
{
	typedef
	Type
	decorated_type;

	template<
		typename Arg
	>
	static
	constexpr
	decorated_type
	get(
		Arg const _value
	)
	{
		FCPPT_CHECK_LITERAL_CONVERSION(
			decorated_type,
			Arg
		);

		return
			static_cast<
				decorated_type
			>(
				_value
			);
	}
};

}

#endif
