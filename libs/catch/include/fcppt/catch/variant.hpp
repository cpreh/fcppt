//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CATCH_VARIANT_HPP_INCLUDED
#define FCPPT_CATCH_VARIANT_HPP_INCLUDED

#include <fcppt/output_to_std_string_convert.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace Catch
{

/**
\brief Output specialization for \link fcppt::variant::object\endlink.

\ingroup fcpptcatch
*/
template<
	typename Types
>
struct StringMaker<
	fcppt::variant::object<
		Types
	>
>
{
	static
	std::string
	convert(
		fcppt::variant::object<
			Types
		> const &_value
	)
	{
		return
			fcppt::output_to_std_string_convert(
				_value
			);
	}
};

}

#endif
