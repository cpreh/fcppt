//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string_literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("string_literal", "[various]")
{
  CHECK(FCPPT_STRING_LITERAL(char, "test") == std::string{"test"});

  CHECK(FCPPT_STRING_LITERAL(wchar_t, "test") == std::wstring{L"test"});

  CHECK(FCPPT_STRING_LITERAL(char16_t, "test") == std::u16string{u"test"});

  CHECK(FCPPT_STRING_LITERAL(char32_t, "test") == std::u32string{U"test"});
}
