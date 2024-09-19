//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/char_type.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/io/scoped_rdbuf.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <ios>
#include <sstream>
#include <streambuf>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("io::scoped_rdbuf", "[io]")
{
  fcppt::io::ostream &stream{fcppt::io::cout()};

  std::basic_streambuf<fcppt::char_type> &old_buffer{*stream.rdbuf()};

  std::basic_stringbuf<fcppt::char_type> buffer{};

  {
    std::basic_ios<fcppt::char_type> &stream_base{stream};

    std::basic_streambuf<fcppt::char_type> &buffer_base{buffer};

    fcppt::io::scoped_rdbuf const scoped_buf{
        fcppt::make_ref(stream_base), fcppt::make_ref(buffer_base)};

    CHECK(stream_base.rdbuf() == &buffer_base);
  }

  CHECK(stream.rdbuf() == &old_buffer);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
