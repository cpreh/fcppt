//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/index.hpp>
#include <fcppt/math/matrix/init.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix access", "[math],[matrix]")
{
  using matrix_type = fcppt::math::matrix::
      static_<fcppt::tuple::object<fcppt::math::size_type, fcppt::math::size_type>, 4, 4>;

  auto const mat{fcppt::math::matrix::init<matrix_type>(
      []<fcppt::math::size_type Row, fcppt::math::size_type Col>(
          fcppt::math::matrix::index<Row, Col>) { return fcppt::tuple::make(Row, Col); })};

  matrix_type mat_nc{mat};

  // Row 0
  CHECK(mat.m00() == fcppt::tuple::make(0U, 0U));

  CHECK(mat.m01() == fcppt::tuple::make(0U, 1U));

  CHECK(mat.m02() == fcppt::tuple::make(0U, 2U));

  CHECK(mat.m03() == fcppt::tuple::make(0U, 3U));

  CHECK(mat_nc.m00() == fcppt::tuple::make(0U, 0U));

  CHECK(mat_nc.m01() == fcppt::tuple::make(0U, 1U));

  CHECK(mat_nc.m02() == fcppt::tuple::make(0U, 2U));

  CHECK(mat_nc.m03() == fcppt::tuple::make(0U, 3U));

  // Row 1
  CHECK(mat.m10() == fcppt::tuple::make(1U, 0U));

  CHECK(mat.m11() == fcppt::tuple::make(1U, 1U));

  CHECK(mat.m12() == fcppt::tuple::make(1U, 2U));

  CHECK(mat.m13() == fcppt::tuple::make(1U, 3U));

  CHECK(mat_nc.m10() == fcppt::tuple::make(1U, 0U));

  CHECK(mat_nc.m11() == fcppt::tuple::make(1U, 1U));

  CHECK(mat_nc.m12() == fcppt::tuple::make(1U, 2U));

  CHECK(mat_nc.m13() == fcppt::tuple::make(1U, 3U));

  // Row 2
  CHECK(mat.m20() == fcppt::tuple::make(2U, 0U));

  CHECK(mat.m21() == fcppt::tuple::make(2U, 1U));

  CHECK(mat.m22() == fcppt::tuple::make(2U, 2U));

  CHECK(mat.m23() == fcppt::tuple::make(2U, 3U));

  CHECK(mat_nc.m20() == fcppt::tuple::make(2U, 0U));

  CHECK(mat_nc.m21() == fcppt::tuple::make(2U, 1U));

  CHECK(mat_nc.m22() == fcppt::tuple::make(2U, 2U));

  CHECK(mat_nc.m23() == fcppt::tuple::make(2U, 3U));

  // Row 3
  CHECK(mat.m30() == fcppt::tuple::make(3U, 0U));

  CHECK(mat.m31() == fcppt::tuple::make(3U, 1U));

  CHECK(mat.m32() == fcppt::tuple::make(3U, 2U));

  CHECK(mat.m33() == fcppt::tuple::make(3U, 3U));

  CHECK(mat_nc.m30() == fcppt::tuple::make(3U, 0U));

  CHECK(mat_nc.m31() == fcppt::tuple::make(3U, 1U));

  CHECK(mat_nc.m32() == fcppt::tuple::make(3U, 2U));

  CHECK(mat_nc.m33() == fcppt::tuple::make(3U, 3U));
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
