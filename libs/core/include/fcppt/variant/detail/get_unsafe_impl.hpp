//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_GET_UNSAFE_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_GET_UNSAFE_IMPL_HPP_INCLUDED

#include <fcppt/variant/detail/has_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <variant>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types,
	typename U,
	typename Variant
>
std::conditional_t<
	std::is_const_v<
		Variant
	>,
	U const &,
	U &
>
get_unsafe_impl(
	Variant &_variant
)
{
	static_assert(
		fcppt::variant::detail::has_type<
			Types,
			U
		>::value,
		"Invalid variant type"
	);

	// TODO: Use get_if if we can get rid of gcc null-dereference warnings
	return
		std::get<
			U
		>(
			_variant
		);
}

}
}
}

#endif
