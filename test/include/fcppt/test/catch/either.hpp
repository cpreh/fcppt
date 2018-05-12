//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TEST_CATCH_EITHER_HPP_INCLUDED
#define FCPPT_TEST_CATCH_EITHER_HPP_INCLUDED

#include <fcppt/insert_to_std_string_convert.hpp>
#include <fcppt/either/object_fwd.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace Catch
{

template<
	typename Failure,
	typename Success
>
struct StringMaker<
	fcppt::either::object<
		Failure,
		Success
	>
>
{
	static
	std::string
	convert(
		fcppt::either::object<
			Failure,
			Success
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
