//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_GET_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_GET_IMPL_HPP_INCLUDED

#include <fcppt/variant/invalid_get.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/index_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Ret,
	typename Variant
>
Ret &
get_impl(
	Variant &_variant
)
{
	typedef typename std::remove_const<
		Ret
	>::type return_type;

	typedef typename Variant::types types;

	if(
		_variant.type_index()
		!=
		static_cast<
			fcppt::variant::size_type
		>(
			fcppt::variant::detail::index_of<
				types,
				return_type
			>::value
		)
	)
		throw fcppt::variant::invalid_get();

	return
		_variant. template get_unchecked<
			return_type
		>();
}

}
}
}

#endif
