//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CATCH_RECURSIVE_HPP_INCLUDED
#define FCPPT_CATCH_RECURSIVE_HPP_INCLUDED

#include <fcppt/recursive_impl.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace Catch
{

/**
\brief Output specialization for \link fcppt::recursive\endlink.

\ingroup fcpptcatch
*/
template<
	typename Types
>
struct StringMaker<
	fcppt::recursive<
		Types
	>
>
{
	static
	std::string
	convert(
		fcppt::recursive<
			Types
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
