//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

namespace
{
template <typename T, fcppt::math::size_type N>
class view_storage
{
public:
  using value_type = T;

  using size_type = fcppt::math::size_type;

  using storage_size = fcppt::math::static_size<N>;

  using pointer = value_type *;

  using reference = value_type &;

  using const_reference = value_type const &;

  explicit view_storage(pointer const _data // NOLINT(misc-misplaced-const)
                        )
      : data_(_data)
  {
  }

  reference operator[](size_type const _index) { return data_[_index]; }

  const_reference operator[](size_type const _index) const { return data_[_index]; }

private:
  pointer data_;
};

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::vector view storage", "[math],[vector]")
{
  using unsigned_view_storage = view_storage<unsigned, 2>;

  using view_vector = fcppt::math::vector::object<unsigned, 2, unsigned_view_storage>;

  std::array<unsigned, 2U> array{{1, 2}};

  view_vector const view{unsigned_view_storage(array.data())};

  using uivector2 = fcppt::math::vector::static_<unsigned, 2>;

  uivector2 const vec(view);

  CHECK(vec == view);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

FCPPT_PP_POP_WARNING
