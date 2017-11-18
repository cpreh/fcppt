//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_EQUAL_HPP_INCLUDED

#include <fcppt/detail/equal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/equal_to.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T1,
	typename T2
>
inline
typename
std::enable_if<
	boost::mpl::equal_to<
		typename
		T1::static_size,
		typename
		T2::static_size
	>::value,
	bool
>::type
array_equal(
	T1 const &_v1,
	T2 const &_v2
)
{
	auto const &storage1(
		_v1.storage()
	);

	return
		fcppt::detail::equal(
			storage1.begin(),
			storage1.end(),
			_v2.storage().begin()
		);
}

}
}
}

#endif
