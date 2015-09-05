//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CONSTRUCT_HPP_INCLUDED

#include <fcppt/algorithm/array_fold_static.hpp>
#include <fcppt/algorithm/array_push_back.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Dest,
	typename Src
>
inline
Dest
construct(
	Src const &_src,
	typename Src::value_type const &_value
)
{
	static_assert(
		Dest::static_size::value
		==
		Src::static_size::value
		+
		1u,
		""
	);

	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		typename
		Dest::storage_type
	);

	typedef
	fcppt::math::static_storage<
		typename
		Src::value_type,
		Src::static_size::value
	>
	storage;

	return
		Dest(
			fcppt::algorithm::array_push_back(
				fcppt::algorithm::array_fold_static<
					storage
				>(
					[
						&_src
					](
						auto const _index
					)
					{
						return
							fcppt::math::at_c<
								_index
							>(
								_src
							);
					}
				),
				_value
			)
		);
}

}
}
}

#endif
