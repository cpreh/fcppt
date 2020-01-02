//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SHARED_PTR_STD_HASH_HPP_INCLUDED
#define FCPPT_SHARED_PTR_STD_HASH_HPP_INCLUDED

#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/shared_ptr_hash_impl.hpp>
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
	fcppt::shared_ptr<
		Type
	>
>
{
	typedef fcppt::shared_ptr<
		Type
	> type;

	std::size_t
	operator()(
		type const &_value
	) const
	noexcept
	{
		return
			fcppt::shared_ptr_hash<
				type
			>()(
				_value
			);
	}
};

FCPPT_PP_POP_WARNING

}

#endif
