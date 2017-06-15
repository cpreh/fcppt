//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_LABEL_IMPL_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_IMPL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/label_decl.hpp>
#include <fcppt/record/detail/element_init_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Tag
>
template<
	typename Arg
>
fcppt::record::detail::element_init<
	Tag,
	typename
	std::decay<
		Arg
	>::type
>
fcppt::record::label<
	Tag
>::operator=(
	Arg &&_arg
)
{
	return
		fcppt::record::detail::element_init<
			Tag,
			typename
			std::decay<
				Arg
			>::type
		>(
			std::forward<
				Arg
			>(
				_arg
			)
		);
}

FCPPT_PP_POP_WARNING

#endif
