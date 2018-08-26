//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_LABEL_NAME_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_NAME_HPP_INCLUDED

#include <fcppt/to_std_string.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/record/is_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Returns the name of a label as a string

\ingroup fcpptrecord
*/
template<
	typename Label
>
inline
std::string
label_name()
{
	static_assert(
		fcppt::record::is_label<
			Label
		>::value,
		"Label must be a label"
	);

	return
		fcppt::to_std_string(
			fcppt::type_name_from_info(
				typeid(
					typename
					Label::tag
				)
			)
		);
}

}
}

#endif
