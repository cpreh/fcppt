//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_FILE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_FILE_HPP_INCLUDED

#include <fcppt/preprocessor/detail/file.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config.hpp>

/// Procudes a string literal for the current file (__FILE__) that is compatible to fcppt::string
#define FCPPT_PP_FILE FCPPT_PP_DETAIL_FILE

#endif
