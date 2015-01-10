//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_IDENTITY_FUN_HPP_INCLUDED
#define FCPPT_CAST_IDENTITY_FUN_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Function object that only allows the identity conversion

\ingroup fcpptcasts
*/
struct identity_fun
{
	template<
		typename Dest,
		typename Source
	>
	Dest
	operator()(
		Source const &_source
	) const
	{
		static_assert(
			std::is_same<
				Dest,
				Source
			>::value,
			"identity_fun can only be used to do an identity conversion"
		);

		return
			_source;
	}
};

}
}

#endif
