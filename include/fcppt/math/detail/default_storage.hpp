//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_DEFAULT_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_DEFAULT_STORAGE_HPP_INCLUDED

#include <fcppt/math/detail/init_storage.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Result
>
Result const
default_storage()
{
	return
		fcppt::math::detail::init_storage<
			Result
		>(
			typename Result::value_type()
		);
}

}
}
}

#endif
