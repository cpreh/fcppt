//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
class base
{
  FCPPT_NONMOVABLE(base);

public:
  base() = default;

  virtual ~base() = default;
};

class derived : public base
{
  FCPPT_NONMOVABLE(derived);

public:
  derived() : base() {}

  ~derived() override = default;
};

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("reference_to_base", "[ref]")
{
  {
    derived nonconst_derived{};

    fcppt::reference<base> const nonconst_base(
        fcppt::reference_to_base<base>(fcppt::make_ref(nonconst_derived)));

    CHECK(&nonconst_derived == &nonconst_base.get());
  }

  {
    derived const const_derived{};

    fcppt::reference<base const> const const_base(
        fcppt::reference_to_base<base const>(fcppt::make_cref(const_derived)));

    CHECK(&const_derived == &const_base.get());
  }
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
