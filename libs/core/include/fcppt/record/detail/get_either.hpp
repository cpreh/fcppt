//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_GET_EITHER_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_GET_EITHER_HPP_INCLUDED

#include <fcppt/move_if.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/get.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename LeftRef,
	typename RightRef,
	typename Label,
	typename Record1,
	typename Record2
>
inline
fcppt::record::label_value_type<
	Record1,
	Label
>
get_either(
	Record1 &_record1,
	Record2 &
)
{
	return
		fcppt::move_if<
			!LeftRef::value
		>(
			fcppt::record::get<
				Label
			>(
				_record1
			)
		);
}

template<
	typename LeftRef,
	typename RightRef,
	typename Label,
	typename Record1,
	typename Record2
>
inline
fcppt::record::label_value_type<
	Record2,
	Label
>
get_either(
	Record1 &,
	Record2 &_record2
)
{
	return
		fcppt::move_if<
			!RightRef::value
		>(
			fcppt::record::get<
				Label
			>(
				_record2
			)
		);
}

}
}
}

#endif
