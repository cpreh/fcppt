//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CATCH_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_CATCH_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace Catch
{

/**
\brief Output specialization for #fcppt::strong_typedef.

\ingroup fcpptcatch
*/
template<
	typename Type,
	typename Tag
>
struct StringMaker<
	fcppt::strong_typedef<
		Type,
		Tag
	>
>
{
	static
	std::string
	convert(
		fcppt::strong_typedef<
			Type,
			Tag
		> const &_value
	)
	{
		return
			fcppt::catch_::convert(
				_value.get()
			);
	}
};

}

#endif
