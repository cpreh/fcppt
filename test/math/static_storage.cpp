//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/detail/static_storage_impl.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

TEST_CASE("math::detail::static_storage", "[math]")
{
  using storage_type = fcppt::math::detail::static_storage<int, 2>;

  {
    storage_type const const_storage{1, 2};

    CHECK(const_storage[0] == 1);

    CHECK(const_storage[1] == 2);

    CHECK(const_storage.data()[0] == 1);

    CHECK(const_storage.data()[1] == 2);
  }

  {
    storage_type storage{1, 2};

    storage[0] = 5;

    CHECK(storage[0] == 5);

    storage.data()[1] = 10;

    CHECK(storage.data()[1] == 10);
  }
}

FCPPT_PP_POP_WARNING

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
