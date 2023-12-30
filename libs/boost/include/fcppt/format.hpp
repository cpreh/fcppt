//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FORMAT_HPP_INCLUDED
#define FCPPT_FORMAT_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/format/format_class.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief A fcppt::char_type typedef for <a
href="http://www.boost.org/doc/libs/1_49_0/libs/format/">boost.format</a>

\ingroup fcpptboost

See \ref fcpptstring for more information about #fcppt::char_type.
*/
using format = boost::basic_format<fcppt::char_type>;

}

#endif
