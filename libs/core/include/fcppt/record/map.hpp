//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_MAP_HPP_INCLUDED
#define FCPPT_RECORD_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/use.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/record/map_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Maps a record using a function.

\ingroup fcpptrecord

For every <code>fcppt::record::element<L,T></code> in \a Record,
<code>_function(get<L>(_record))</code> is stored in the result type.

\tparam Record An #fcppt::record::object.

\tparam Function a polymorphic function that can be called with every type in \a Record.

\see fcppt::record::map_result
*/
template<
	typename Record,
	typename Function
>
inline
fcppt::record::map_result<
	Record,
	Function
>
map(
	Record &&_record,
	Function const &_function
)
{
	return
		fcppt::record::init<
			fcppt::record::map_result<
				Record,
				Function
			>
		>(
			[
				&_record,
				&_function
			](
				auto const _element
			)
			{
				FCPPT_USE(
					_element
				);

				return
					_function(
						fcppt::move_if_rvalue<
							Record
						>(
							fcppt::record::get<
								fcppt::record::element_to_label<
									std::remove_const_t<
										decltype(
											_element
										)
									>
								>
							>(
								_record
							)
						)
					);
			}
		);
}

}
}

#endif
