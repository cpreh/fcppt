//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_TO_DIFFERENT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_TO_DIFFERENT_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/init.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Dest,
	typename Source
>
inline
Dest
to_different(
	Source const &_source
)
{
	static_assert(
		Dest::dim_wrapper::value
		==
		Source::dim_wrapper::value,
		"dim_wrappers must match"
	);

	return
		fcppt::math::detail::init<
			Dest
		>(
			[
				&_source
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					fcppt::math::detail::checked_access<
						_index
					>(
						_source
					);
			}
		);
}

}
}
}

#endif
