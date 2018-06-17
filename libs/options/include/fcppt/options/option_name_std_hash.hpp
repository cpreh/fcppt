//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTION_NAME_STD_HASH_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_NAME_STD_HASH_HPP_INCLUDED

#include <fcppt/options/option_name_fwd.hpp>
#include <fcppt/options/option_name_hash.hpp>
#include <fcppt/config/compiler.hpp>
#if defined(FCPPT_CONFIG_CLANG_COMPILER)
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace std
{

#if defined(FCPPT_CONFIG_CLANG_COMPILER)
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wmismatched-tags)
#endif

template<>
struct hash<
	fcppt::options::option_name
>
{
	std::size_t
	operator()(
		fcppt::options::option_name const &_name
	) const
	{
		return
			fcppt::options::option_name_hash(
				_name
			);
	}
};

#if defined(FCPPT_CONFIG_CLANG_COMPILER)
FCPPT_PP_POP_WARNING
#endif

}

#endif
