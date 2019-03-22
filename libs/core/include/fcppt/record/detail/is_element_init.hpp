//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_IS_ELEMENT_INIT_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_IS_ELEMENT_INIT_HPP_INCLUDED

#include <fcppt/record/detail/element_init_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Type
>
struct is_element_init
:
std::false_type
{
};

template<
	typename Tag,
	typename Type
>
struct is_element_init<
	fcppt::record::detail::element_init<
		Tag,
		Type
	>
>
:
std::true_type
{
};

}
}
}

#endif
