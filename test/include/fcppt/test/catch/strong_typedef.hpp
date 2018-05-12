//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TEST_CATCH_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_TEST_CATCH_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/insert_to_std_string_convert.hpp>
#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace Catch
{

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
			fcppt::insert_to_std_string_convert(
				_value
			);
	}
};

}

#endif
