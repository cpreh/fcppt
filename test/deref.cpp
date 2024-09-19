//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/deref.hpp>
#include <fcppt/deref_recursive.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/deref_reference.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/deref_type.hpp>
#include <fcppt/deref_unique_ptr.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/recursive_impl.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("deref value", "[various]")
{
  int x{0};

  CHECK(&fcppt::deref(x) == &x);

  static_assert(std::is_same_v<fcppt::deref_type<int>, int &>);
}

TEST_CASE("deref const value", "[various]")
{
  int const x{0};

  CHECK(&fcppt::deref(x) == &x);

  static_assert(std::is_same_v<fcppt::deref_type<int const>, int const &>);
}

TEST_CASE("deref reference", "[various]")
{
  int x{0};

  fcppt::reference<int> ref{x};

  CHECK(&fcppt::deref(ref) == &x);

  fcppt::reference<int> const cref{x};

  CHECK(&fcppt::deref(cref) == &x);

  static_assert(std::is_same_v<fcppt::deref_type<fcppt::reference<int>>, int &>);
}

TEST_CASE("deref const reference", "[various]")
{
  int const x{0};

  fcppt::reference<int const> ref{x};

  CHECK(&fcppt::deref(ref) == &x);

  fcppt::reference<int const> const cref{x};

  CHECK(&fcppt::deref(cref) == &x);

  static_assert(std::is_same_v<fcppt::deref_type<fcppt::reference<int const>>, int const &>);
}

TEST_CASE("deref reference nested", "[various]")
{
  int x{0};

  fcppt::reference<int> ref_inner{x};

  fcppt::reference<fcppt::reference<int>> ref{ref_inner};

  CHECK(&fcppt::deref(ref) == &x);

  static_assert(std::is_same_v<fcppt::deref_type<fcppt::reference<fcppt::reference<int>>>, int &>);
}

TEST_CASE("deref reference nested 2", "[various]")
{
  fcppt::unique_ptr<int> ptr{fcppt::make_unique_ptr<int>(0)};

  fcppt::reference<fcppt::unique_ptr<int>> ref{ptr};

  CHECK(&fcppt::deref(ref) == ptr.get_pointer());

  static_assert(std::is_same_v<fcppt::deref_type<fcppt::reference<fcppt::unique_ptr<int>>>, int &>);
}

TEST_CASE("deref reference nested 3", "[various]")
{
  fcppt::unique_ptr<int> const ptr{fcppt::make_unique_ptr<int>(0)};

  fcppt::reference<fcppt::unique_ptr<int> const> ref{ptr};

  CHECK(&fcppt::deref(ref) == ptr.get_pointer());

  static_assert(
      std::is_same_v<fcppt::deref_type<fcppt::reference<fcppt::unique_ptr<int> const>>, int &>);
}

TEST_CASE("deref unique_ptr", "[various]")
{
  fcppt::unique_ptr<int> ptr{fcppt::make_unique_ptr<int>(0)};

  CHECK(&fcppt::deref(ptr) == ptr.get_pointer());

  fcppt::unique_ptr<int> const cptr{fcppt::make_unique_ptr<int>(0)};

  CHECK(&fcppt::deref(cptr) == cptr.get_pointer());

  static_assert(std::is_same_v<fcppt::deref_type<fcppt::unique_ptr<int>>, int &>);
}

TEST_CASE("deref recursive", "[various]")
{
  fcppt::recursive<int> rec{10};

  CHECK(&fcppt::deref(rec) == &rec.get());

  fcppt::recursive<int> const crec{10};

  CHECK(&fcppt::deref(crec) == &crec.get());

  static_assert(std::is_same_v<fcppt::deref_type<fcppt::recursive<int>>, int &>);
  static_assert(std::is_same_v<fcppt::deref_type<fcppt::recursive<int> const>, int const &>);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
