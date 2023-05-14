//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/unique_ptr_to_const.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{
//! [unique_ptr_factory]
using unique_int_ptr = fcppt::unique_ptr<int>;

// Create a unique_ptr factory
unique_int_ptr int_ptr_factory()
{
  // make_unique_ptr is a factory function to make a unique_ptr An
  // rvalue is returned here, so no moving is necessary.
  return fcppt::make_unique_ptr<int>(1);
}
//! [unique_ptr_factory]

//! [unique_ptr_factory_use]
void int_ptr_arg(unique_int_ptr &&ptr) { std::cout << *ptr << '\n'; }

void test() { int_ptr_arg(int_ptr_factory()); }
//! [unique_ptr_factory_use]

//! [unique_ptr_move]
unique_int_ptr test2()
{
  // ptr is a named object
  unique_int_ptr ptr(fcppt::make_unique_ptr<int>(1));

  // ptr must be moved here to take ownership away from it
  return ptr;
}
//! [unique_ptr_move]

//! [unique_ptr_move_dangerous]
void test3()
{
  unique_int_ptr ptr(fcppt::make_unique_ptr<int>(1));

  // Implicit move is not allowed
  /*
  int_ptr_arg(ptr	);
  */

  // Make the move explicit
  int_ptr_arg(std::move(ptr));

  // ptr is now the null pointer
  std::cout << ptr.get_pointer() // NOLINT(bugprone-use-after-move,hicpp-invalid-access-moved)
            << '\n';
}
//! [unique_ptr_move_dangerous]
}

namespace
{
using shared_int_ptr = fcppt::shared_ptr<int>;

shared_int_ptr to_shared_ptr(unique_int_ptr ptr)
{
  // fcppt::shared_ptr can take a unique_ptr,
  // but because ptr is an lvalue, we have to move it
  // note: move is found via ADL
  return shared_int_ptr(std::move(ptr));
}

}

namespace
{
//! [unique_ptr_to_base]
struct base
{
  FCPPT_NONMOVABLE(base);

  base() = default;

  virtual ~base() = default;
};

struct derived : base
{
  FCPPT_NONMOVABLE(derived);

  derived() = default;

  ~derived() override = default;
};

void test4()
{
  using base_ptr = fcppt::unique_ptr<base>;

  base_ptr const foo{fcppt::unique_ptr_to_base<base>(fcppt::make_unique_ptr<derived>())};
}
//! [unique_ptr_to_base]

}

namespace
{
void test5()
{
  //! [unique_ptr_to_const]
  using const_int_ptr = fcppt::unique_ptr<int const>;

  const_int_ptr const foo{fcppt::unique_ptr_to_const(fcppt::make_unique_ptr<int>(1))};
  //! [unique_ptr_to_const]
}

}

namespace
{
void test6()
{
  //! [unique_ptr_const]
  using scoped_int_ptr = fcppt::unique_ptr<int const>;

  scoped_int_ptr const ptr(fcppt::make_unique_ptr<int const>(1));
  //! [unique_ptr_const]
}

}

namespace
{
//! [unique_ptr_pimpl_header]
class foo_impl;

class foo
{
  // Explicitly disable copying and moving
  FCPPT_NONMOVABLE(foo);

public:
  foo();

  ~foo();

private:
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
  fcppt::unique_ptr<foo_impl> const impl_;
};
//! [unique_ptr_pimpl_header]

//! [unique_ptr_pimpl_cpp]
class foo_impl
{
  // Something here
};

foo::foo() : impl_(fcppt::make_unique_ptr<foo_impl>()) {}

foo::~foo() = default;
//! [unique_ptr_pimpl_cpp]
}

int main()
{
  ::test();

  ::test2();

  ::to_shared_ptr(::int_ptr_factory());

  ::test3();

  ::test4();

  ::test5();

  ::test6();

  foo const f{};
}
