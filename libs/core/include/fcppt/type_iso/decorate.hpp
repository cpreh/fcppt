//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_DECORATE_HPP_INCLUDED
#define FCPPT_TYPE_ISO_DECORATE_HPP_INCLUDED

#include <fcppt/type_iso/undecorated_type.hpp>
#include <fcppt/type_iso/detail/decorate.hpp>


namespace fcppt
{
namespace type_iso
{

/**
\brief Decorates a value

Decorates \a _value by applying all (nested) type constructors of \a Result.

\ingroup fcppttypeiso
*/
template<
	typename Result
>
inline
Result
decorate(
	fcppt::type_iso::undecorated_type<
		Result
	> const &_value
)
{
	return
		fcppt::type_iso::detail::decorate<
			Result
		>(
			_value
		);
}

}
}

#endif
