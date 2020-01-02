//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_STD_HASH_HPP_INCLUDED
#define FCPPT_REFERENCE_STD_HASH_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/reference_hash_impl.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace std
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wmismatched-tags)

template<
	typename Type
>
struct hash<
	fcppt::reference<
		Type
	>
>
{
	typedef fcppt::reference<
		Type
	> type;

	std::size_t
	operator()(
		type const &_value
	) const
	noexcept
	{
		return
			fcppt::reference_hash<
				type
			>()(
				_value
			);
	}
};

FCPPT_PP_POP_WARNING

}

#endif
