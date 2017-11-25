//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_LABEL_IS_SAME_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_LABEL_IS_SAME_HPP_INCLUDED

#include <fcppt/record/label_fwd.hpp>
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
	typename Tag,
	typename Type
>
struct label_is_same;

template<
	typename Tag1,
	typename Tag2,
	typename Type
>
struct label_is_same<
	fcppt::record::label<
		Tag1
	>,
	fcppt::record::detail::element_init<
		Tag2,
		Type
	>
>
:
std::is_same<
	Tag1,
	Tag2
>
{
};

}
}
}

#endif
