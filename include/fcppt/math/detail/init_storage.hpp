//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INIT_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INIT_STORAGE_HPP_INCLUDED

#include <fcppt/algorithm/array_init.hpp>


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
init_storage(
	typename Result::value_type const &_value
)
{
	return
		fcppt::algorithm::array_init<
			Result
		>(
			_value
		);
}

}
}
}

#endif
