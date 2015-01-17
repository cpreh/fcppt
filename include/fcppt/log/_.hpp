//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG___HPP_INCLUDED
#define FCPPT_LOG___HPP_INCLUDED

#include <fcppt/log/detail/output_helper.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/detail/temporary_output.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Trampoline to create logger output

\ingroup fcpptlog

This trampoline refers to an object that has <code>operator << </code>
overloaded and accepts every input an <code>std::basic_ostream</code> does.
*/
FCPPT_LOG_DETAIL_SYMBOL extern
fcppt::log::detail::output_helper const _;

}
}

#endif
