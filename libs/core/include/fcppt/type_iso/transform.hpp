//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_ISO_TRANSFORM_HPP_INCLUDED
#define FCPPT_TYPE_ISO_TRANSFORM_HPP_INCLUDED

#include <fcppt/type_iso/transform_fwd.hpp>
#include <fcppt/type_iso/detail/terminal_tag.hpp>


namespace fcppt
{
namespace type_iso
{

template<
	typename Type,
	typename Enable
>
struct transform
:
fcppt::type_iso::detail::terminal_tag
{
};

}
}

#endif
