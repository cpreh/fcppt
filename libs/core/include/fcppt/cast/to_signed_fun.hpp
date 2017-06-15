//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TO_SIGNED_FUN_HPP_INCLUDED
#define FCPPT_CAST_TO_SIGNED_FUN_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Function object of fcppt::cast::to_signed

\ingroup fcpptcasts
*/
struct to_signed_fun
{
	template<
		typename Dest,
		typename Source
	>
	constexpr
	static
	Dest
	execute(
		Source const &_source
	)
	noexcept
	{
		static_assert(
			std::is_same<
				decltype(
					fcppt::cast::to_signed(
						std::declval<
							Source
						>()
					)
				),
				Dest
			>::value,
			"Mismatched types in to_signed_fun"
		);

		return
			fcppt::cast::to_signed(
				_source
			);
	}
};

}
}

#endif
