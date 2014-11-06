//          Copyright Carl Philipp Reh 2009 - 2014.
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

template<
	typename Type
>
struct make_literal<
	Type,
	typename
	std::enable_if<
		std::is_fundamental<
			Type
		>::value
	>::type
>
{
	template<
		typename Fundamental
	>
	static
	constexpr
	Type
	get(
		Fundamental const _fundamental
	)
	{
		FCPPT_CHECK_LITERAL_CONVERSION(
			Type,
			Fundamental
		);

		return
			static_cast<
				Type
			>(
				_fundamental
			);
	}
};

}

#endif
