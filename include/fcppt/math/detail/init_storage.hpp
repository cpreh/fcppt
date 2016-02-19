//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INIT_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INIT_STORAGE_HPP_INCLUDED

#include <fcppt/algorithm/array_init_const.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Result
>
inline
Result
init_storage(
	typename Result::value_type const &_value
)
{
	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		Result
	);

	return
		fcppt::algorithm::array_init_const<
			Result
		>(
			_value
		);
}

}
}
}

#endif
