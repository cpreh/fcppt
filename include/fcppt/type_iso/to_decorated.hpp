//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_TO_DECORATED_HPP_INCLUDED
#define FCPPT_TYPE_ISO_TO_DECORATED_HPP_INCLUDED

#include <fcppt/type_iso/base_type.hpp>
#include <fcppt/type_iso/detail/to_decorated.hpp>


namespace fcppt
{
namespace type_iso
{

template<
	typename Result
>
inline
Result
to_decorated(
	fcppt::type_iso::base_type<
		Result
	> const &_value
)
{
	return
		fcppt::type_iso::detail::to_decorated<
			Result
		>(
			_value
		);
}

}
}

#endif
