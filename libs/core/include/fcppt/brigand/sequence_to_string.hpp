//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_SEQUENCE_TO_STRING_HPP_INCLUDED
#define FCPPT_BRIGAND_SEQUENCE_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/algorithm/loop_break_brigand.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Converts a sequence to a string

\ingroup fcpptbrigand

\tparam Sequence Must be an BRIGAND sequence
*/
template<
	typename Sequence
>
fcppt::string
sequence_to_string()
{
	return
		FCPPT_TEXT('[')
		+
		fcppt::algorithm::fold(
			Sequence{},
			fcppt::string{},
			[](
				auto const _current_type,
				fcppt::string &&_result
			)
			{
				FCPPT_USE(
					_current_type
				);

				return
					std::move(
						_result
					)
					+
					fcppt::type_name_from_info(
						typeid(
							fcppt::tag_type<
								decltype(
									_current_type
								)
							>
						)
					)
					+
					FCPPT_TEXT(", ");
			}
		)
		+
		FCPPT_TEXT(']');
}

}
}

#endif
