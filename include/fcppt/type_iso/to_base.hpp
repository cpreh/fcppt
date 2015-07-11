//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_TO_BASE_HPP_INCLUDED
#define FCPPT_TYPE_ISO_TO_BASE_HPP_INCLUDED

#include <fcppt/type_iso/base_type.hpp>
#include <fcppt/type_iso/detail/to_base.hpp>


namespace fcppt
{
namespace type_iso
{

template<
	typename Type
>
inline
fcppt::type_iso::base_type<
	Type
>
to_base(
	Type const &_value
)
{
	return
		fcppt::type_iso::detail::to_base(
			_value
		);
}

}
}

#endif
