//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_NULL_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_NULL_STORAGE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/detail/init_storage.hpp>
#include <fcppt/type_traits/value_type.hpp>


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
null_storage()
{
	return
		fcppt::math::detail::init_storage<
			Result
		>(
			fcppt::literal<
				fcppt::type_traits::value_type<
					Result
				>
			>(
				0
			)
		);
}

}
}
}

#endif
