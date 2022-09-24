//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/char_type.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/io/scoped_rdbuf.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <streambuf>
#include <fcppt/config/external_end.hpp>

int main()
{
  fcppt::io::ostringstream const ostream{};

  {
    fcppt::io::scoped_rdbuf const scoped{
        fcppt::reference_to_base<std::basic_ios<fcppt::char_type>>(
            fcppt::make_ref(fcppt::io::cout())),
        fcppt::reference_to_base<std::basic_streambuf<fcppt::char_type>>(
            fcppt::make_ref(*ostream.rdbuf()))};

    fcppt::io::cout() << FCPPT_TEXT("This is a test!\n");
  }

  fcppt::io::cout() << ostream.str();
}
