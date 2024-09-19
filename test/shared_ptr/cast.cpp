//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const_pointer_cast.hpp>
#include <fcppt/dynamic_pointer_cast.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/static_pointer_cast.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
class base
{
public:
  FCPPT_NONMOVABLE(base);

  base() = default;

  virtual ~base() = default;
};

class derived : public base
{
public:
  FCPPT_NONMOVABLE(derived);

  derived() = default;

  ~derived() override = default;
};

using base_ptr = fcppt::shared_ptr<base>;

using derived_ptr = fcppt::shared_ptr<derived>;

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("dynamic_pointer_cast", "[smartptr]")
{
  base_ptr const ptr(fcppt::make_shared_ptr<derived>());

  {
    fcppt::optional::object<derived_ptr> const ptr2(fcppt::dynamic_pointer_cast<derived>(ptr));

    CHECK(ptr2.has_value());

    fcppt::optional::maybe(
        ptr2,
        [] { CHECK(false); },
        [&ptr](derived_ptr const &_ptr2) { CHECK(ptr.use_count() == _ptr2.use_count()); });
  }

  CHECK(ptr.use_count() == 1L);
}

TEST_CASE("static_pointer_cast", "[smartptr]")
{
  base_ptr const ptr(fcppt::make_shared_ptr<derived>());

  {
    derived_ptr const ptr2(fcppt::static_pointer_cast<derived>(ptr));

    CHECK(ptr.use_count() == ptr2.use_count());
  }

  CHECK(ptr.use_count() == 1L);
}

TEST_CASE("const_pointer_cast", "[smartptr]")
{
  using const_base_ptr = fcppt::shared_ptr<base const>;

  const_base_ptr const ptr(fcppt::make_shared_ptr<base>());

  {
    base_ptr const ptr2(fcppt::const_pointer_cast<base>(ptr));

    CHECK(ptr.use_count() == ptr2.use_count());
  }

  CHECK(ptr.use_count() == 1L);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
