//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/char_literal.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("char_literal", "[various]")
{
  CHECK(FCPPT_CHAR_LITERAL(char, 't') == 't');

  CHECK(FCPPT_CHAR_LITERAL(wchar_t, 't') == L't');

  CHECK(FCPPT_CHAR_LITERAL(char16_t, 't') == u't');

  CHECK(FCPPT_CHAR_LITERAL(char32_t, 't') == U't');
}

FCPPT_CATCH_END
