//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_INIT_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_INIT_HPP_INCLUDED

#include <fcppt/algorithm/array_fold_static.hpp>
#include <fcppt/algorithm/detail/array_init_function.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Constructs an array from a value

\ingroup fcpptalgorithm

Constructs an array of type \a Array by initializing every element with \a
_value.

\tparam Array Must be a std::array

\param _value The value to initialize every element with
*/
template<
	typename Array
>
typename boost::enable_if<
	fcppt::type_traits::is_std_array<
		Array
	>,
	Array
>::type
array_init(
	typename Array::value_type const &_value
)
{
	return
		fcppt::algorithm::array_fold_static<
			Array
		>(
			fcppt::algorithm::detail::array_init_function<
				typename Array::value_type
			>(
				_value
			)
		);
}

}
}

#endif
