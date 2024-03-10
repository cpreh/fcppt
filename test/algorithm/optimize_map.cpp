//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/int_range_impl.hpp>
#include <fcppt/not.hpp>
#include <fcppt/algorithm/detail/has_reserve.hpp>
#include <fcppt/algorithm/detail/optimize_map_v.hpp>
#include <fcppt/container/detail/has_size.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/pos_range.hpp>
#include <fcppt/container/grid/pos_ref_range.hpp>
#include <fcppt/enum/range_impl.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <list>
#include <map>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
using int_vector = std::vector<int>;

template <typename Source>
inline constexpr bool source_optimized = fcppt::algorithm::detail::optimize_map_v<int_vector, Source>;

}

int main()
{
  using int_int_map = std::map<int, int>;

  static_assert(
      fcppt::algorithm::detail::optimize_map_v<int_vector, int_vector>,
      "map from vector to vector not optimized");

  static_assert(
      fcppt::container::detail::has_size<int_vector>::value, "vector::size() not detected");

  static_assert(
      fcppt::algorithm::detail::has_reserve<int_vector>::value, "vector::reserve() not detected");

  static_assert(
      fcppt::not_(fcppt::algorithm::detail::has_reserve<int_int_map>::value),
      "map does not have reserve");

  static_assert(fcppt::container::detail::has_size<int_int_map>::value, "map::size() not detected");

  static_assert(
      fcppt::algorithm::detail::optimize_map_v<int_vector, int_int_map>,
      "map from map to vector not optimized");

  static_assert(
      fcppt::not_(fcppt::algorithm::detail::optimize_map_v<int_int_map, int_vector>),
      "map from vector to map cannot be optimized");

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_CLANG_WARNING(-Wunneeded-member-function)
  FCPPT_PP_DISABLE_CLANG_WARNING(-Wunused-member-function)
  FCPPT_PP_DISABLE_VC_WARNING(4822)

  struct ra_range
  {
    using iterator = int_vector::iterator;

    [[nodiscard]] iterator begin() const;

    [[nodiscard]] iterator end() const;
  };

  static_assert(source_optimized<ra_range>, "random access iterator not detected");

  struct bi_range
  {
    using iterator = std::list<int>::iterator;

    [[nodiscard]] iterator begin() const;

    [[nodiscard]] iterator end() const;
  };

  static_assert(
      fcppt::not_(source_optimized<bi_range>), "random access iterator not detected");

  FCPPT_PP_POP_WARNING

  enum class test_enum : std::uint8_t
  {
    test1,
    fcppt_maximum = test1
  };

  static_assert(
      source_optimized<fcppt::enum_::range<test_enum>>, "enum range not optimized");

  static_assert(source_optimized<fcppt::int_range<int>>, "int range not optimized");

  static_assert(
      source_optimized<fcppt::container::grid::pos_range<unsigned, 2>>,
      "grid::pos_range not optimized");

  static_assert(
      source_optimized<fcppt::container::grid::pos_ref_range<
          fcppt::container::grid::object<unsigned, 2>>>,
      "grid::pos_ref_range not optimized");

  static_assert(source_optimized<fcppt::mpl::list::object<int>>, "mpl vector not optimized");
}
