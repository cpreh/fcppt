//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_HAS_VALUE_ALL_HPP_INCLUDED
#define FCPPT_DETAIL_HAS_VALUE_ALL_HPP_INCLUDED

#include <fcppt/detail/check_optional.hpp>


namespace fcppt
{
namespace detail
{

// TODO: Express this using ranges and algorithms
inline
bool
has_value_all()
{
	return
		true;
}

template<
	typename Optional,
	typename... Optionals
>
inline
bool
has_value_all(
	Optional const &_optional,
	Optionals const &... _optionals
)
{
	static_assert(
		fcppt::detail::check_optional<
			Optional
		>::value,
		"Optional must be an optional"
	);

	return
		_optional.has_value()
		&&
		fcppt::detail::has_value_all(
			_optionals...
		);
}

}
}

#endif
