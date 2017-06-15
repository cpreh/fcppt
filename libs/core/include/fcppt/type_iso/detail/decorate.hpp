//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_DETAIL_DECORATE_HPP_INCLUDED
#define FCPPT_TYPE_ISO_DETAIL_DECORATE_HPP_INCLUDED

#include <fcppt/type_iso/transform.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_iso
{
namespace detail
{

template<
	typename Result,
	typename Type
>
inline
typename
std::enable_if<
	std::is_same<
		Result,
		Type
	>::value,
	Result
>::type
decorate(
	Type const &_value
)
{
	return
		_value;
}

template<
	typename Result,
	typename Type
>
inline
typename
std::enable_if<
	!std::is_same<
		Result,
		Type
	>::value,
	Result
>::type
decorate(
	Type const &_value
)
{
	typedef
	fcppt::type_iso::transform<
		Result
	>
	transform_type;

	return
		transform_type::decorate(
			fcppt::type_iso::detail::decorate<
				typename
				transform_type::undecorated_type
			>(
				_value
			)
		);
}

}
}
}

#endif
