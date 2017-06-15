//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_IS_LABEL_HPP_INCLUDED
#define FCPPT_RECORD_IS_LABEL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/label_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Tests if a type is an \link fcppt::record::label\endlink.

\ingroup fcpptrecord
*/
template<
	typename
>
struct is_label
:
std::false_type
{
};

template<
	typename Tag
>
struct is_label<
	fcppt::record::label<
		Tag
	>
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
