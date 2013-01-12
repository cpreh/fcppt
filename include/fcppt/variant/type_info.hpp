//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_TYPE_INFO_HPP_INCLUDED
#define FCPPT_VARIANT_TYPE_INFO_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/detail/type_info.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Returns an <code>std::%type_info</code> of the held type

\ingroup fcpptvariant
*/
template<
	typename Types
>
std::type_info const &
type_info(
	fcppt::variant::object<
		Types
	> const &_variant
)
{
	return
		fcppt::variant::apply_unary(
			fcppt::variant::detail::type_info(),
			_variant
		);
}

}
}

#endif
