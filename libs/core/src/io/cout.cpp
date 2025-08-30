//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/public_config.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

fcppt::io::ostream &fcppt::io::cout()
{
  return
#ifdef FCPPT_NARROW_STRING
      std::cout
#else
      std::wcout
#endif
      ;
}
