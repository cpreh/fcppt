//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_LITERAL_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_MAKE_LITERAL_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/check_literal_conversion.hpp>
#include <fcppt/make_literal_fwd.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/cast/static_cast_fun.hpp>


namespace fcppt
{

/**
\ingroup fcpptliteral
*/
template<
	typename Type,
	typename Tag
>
struct make_literal<
	fcppt::strong_typedef<
		Type,
		Tag
	>
>
{
	typedef
	fcppt::strong_typedef<
		Type,
		Tag
	>
	decorated_type;

	template<
		typename Fundamental
	>
	static
	decorated_type
	get(
		Fundamental const _fundamental
	)
	{
		FCPPT_CHECK_LITERAL_CONVERSION(
			Type,
			Fundamental
		);

		return
			fcppt::strong_typedef_construct_cast<
				decorated_type,
				fcppt::cast::static_cast_fun
			>(
				_fundamental
			);
	}
};

}

#endif
