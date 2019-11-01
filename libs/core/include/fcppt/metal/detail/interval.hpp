//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_DETAIL_INTERVAL_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_INTERVAL_HPP_INCLUDED

#include <fcppt/cast/static_cast_fun.hpp>
#include <fcppt/type_traits/integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/always.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/iota.hpp>
#include <metal/list/transform.hpp>
#include <metal/number/number.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace detail
{

template<
	typename Type,
	Type Begin,
	Type End
>
struct interval
{
	static_assert(
		std::is_integral_v<
			Type
		>
	);

	static_assert(
		Begin
		<=
		End
	);

	typedef
	::metal::transform<
		::metal::bind<
			::metal::lambda<
				fcppt::type_traits::integral_cast
			>,
			::metal::always<
				Type
			>,
			::metal::always<
				fcppt::cast::static_cast_fun
			>,
			::metal::_1
		>,
		::metal::iota<
			::metal::number<
				static_cast<
					::metal::int_
				>(
					Begin
				)
			>,
			::metal::number<
				static_cast<
					::metal::int_
				>(
					End
					-
					Begin
				)
			>
		>
	>
	type;
};

}
}
}

#endif
