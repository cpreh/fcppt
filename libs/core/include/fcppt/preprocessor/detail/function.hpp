//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_FUNCTION_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_FUNCTION_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>


#if defined(FCPPT_CONFIG_GCC_COMPILER)
#include <fcppt/from_std_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>
#	define FCPPT_PP_DETAIL_FUNCTION \
	fcppt::from_std_string( \
		std::string_view{\
			static_cast< \
				char const * \
			>( \
				__PRETTY_FUNCTION__ \
			) \
		}\
	)
#elif defined(FCPPT_CONFIG_MSVC_COMPILER)
#include <fcppt/from_std_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>
#	define FCPPT_PP_DETAIL_FUNCTION \
	fcppt::from_std_string(\
		std::string_view{\
			__FUNCSIG__\
		}\
	)
#else
#include <fcppt/string.hpp>
#	define FCPPT_PP_DETAIL_FUNCTION \
	fcppt::string{}
#endif

#endif
