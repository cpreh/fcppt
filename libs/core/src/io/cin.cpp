//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/public_config.hpp>
#include <fcppt/io/cin.hpp>
#include <fcppt/io/istream_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

fcppt::io::istream &fcppt::io::cin()
{
  return
#if defined(FCPPT_NARROW_STRING)
      std::cin
#else
      std::wcin
#endif
      ;
}
