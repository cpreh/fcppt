//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_IS_OBJECT_HPP_INCLUDED
#define FCPPT_VARIANT_IS_OBJECT_HPP_INCLUDED

#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

template<
	typename Type
>
struct is_object
:
std::false_type
{
};

template<
	typename Types
>
struct is_object<
	fcppt::variant::object<
		Types
	>
>
:
std::true_type
{
};

}
}

#endif
