//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_LABEL_VALUE_TYPE_TPL_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_VALUE_TYPE_TPL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element_to_type_tpl.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/is_object.hpp>
#include <fcppt/record/detail/find_element_deref.hpp>


namespace fcppt
{
namespace record
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Metafunction that computes the value type of a label inside a record

\ingroup fcpptrecord

Returns the type the label \a Label has in \a Record.
*/
template<
	typename Record,
	typename Label
>
struct label_value_type_tpl
:
fcppt::record::element_to_type_tpl<
	fcppt::record::detail::find_element_deref<
		fcppt::record::element_vector<
			Record
		>,
		Label
	>
>
{
	static_assert(
		fcppt::record::is_object<
			Record
		>::value,
		"Record must be an fcppt::record::object"
	);
};

FCPPT_PP_POP_WARNING

}
}

#endif
