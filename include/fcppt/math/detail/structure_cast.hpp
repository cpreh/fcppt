//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/cast/apply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	typename Conv,
	typename U
>
inline
T
structure_cast(
	U const &_other
)
{
	typedef
	fcppt::cast::apply<
		Conv,
		typename T::value_type
	>
	op_type;

	op_type const op{};

	static_assert(
		std::is_same<
			typename T::dim_wrapper,
			typename U::dim_wrapper
		>::value,
		"structure_cast works only on types with the same dimensions"
	);

	return
		T(
			boost::make_transform_iterator(
				_other.begin(),
				op
			),
			boost::make_transform_iterator(
				_other.end(),
				op
			)
		);
}

}
}
}

#endif
