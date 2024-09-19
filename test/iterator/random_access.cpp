//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/iterator/types_from.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
using string_vector = std::vector<std::string>;

template <bool IsConst>
using iterator_type =
    std::conditional_t<IsConst, string_vector::const_iterator, string_vector::iterator>;

template <bool IsConst>
class iterator_tpl;

template <bool IsConst>
using base_type = fcppt::iterator::base<
    fcppt::iterator::types_from<iterator_tpl<IsConst>, iterator_type<IsConst>>>;

template <bool IsConst>
class iterator_tpl : public base_type<IsConst>
{
public:
  using base = base_type<IsConst>;

  using reference = typename base::reference;

  using difference_type = typename base::difference_type;

  using impl_type = iterator_type<IsConst>;

  iterator_tpl() : impl_{} {}

  explicit iterator_tpl(impl_type const _it) : impl_{_it} {}

  [[nodiscard]] reference dereference() const { return *impl_; }

  void increment() { ++impl_; }

  [[nodiscard]] bool equal(iterator_tpl const &_other) const { return impl_ == _other.impl_; }

  void decrement() { --impl_; }

  void advance(difference_type const _diff) { impl_ += _diff; }

  [[nodiscard]] difference_type distance_to(iterator_tpl const &_other) const
  {
    return _other.impl_ - impl_;
  }

private:
  impl_type impl_;
};

using const_iterator = iterator_tpl<true>;

using iterator = iterator_tpl<false>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wglobal-constructors)
FCPPT_PP_DISABLE_CLANG_WARNING(-Wexit-time-destructors)

// NOLINTNEXTLINE(fuchsia-statically-constructed-objects,cert-err58-cpp)
string_vector const vec_c{"1", "2", "3"};

FCPPT_PP_POP_WARNING

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("iterator random access def_ctor", "[iterator]")
{
  iterator it1{};

  iterator it2{};

  CHECK(it1 == it2);
}

TEST_CASE("iterator random access increment_decrement"
          "[iterator]")
{
  const_iterator it{vec_c.begin()};

  ++it;

  CHECK(*it == "2");

  CHECK(&*it == &vec_c[1]);

  --it;

  CHECK(*it == "1");

  CHECK(&*it == vec_c.data());

  CHECK(&*it++ == vec_c.data());

  CHECK(&*it == &vec_c[1]);

  CHECK(&*it-- == &vec_c[1]);

  CHECK(&*it == vec_c.data());
}

TEST_CASE("iterator_range swap", "[iterator]")
{
  const_iterator it1{vec_c.begin()};

  const_iterator it2{vec_c.begin() + 1};

  swap(it1, it2);

  CHECK(*it1 == "2");

  CHECK(*it2 == "1");
}

TEST_CASE("iterator random access advance", "[iterator]")
{
  const_iterator it{vec_c.begin()};

  REQUIRE(&*(it += 2) == &vec_c[2]);

  REQUIRE(&*it == &vec_c[2]);

  {
    const_iterator const temp{const_iterator{vec_c.begin()} + 2};

    CHECK(&*temp == &vec_c[2]);

    CHECK(temp == it);
  }

  CHECK(2 + const_iterator{vec_c.begin()} == it);

  CHECK(it - 2 == const_iterator{vec_c.begin()});

  it -= 1;

  CHECK(&*it == &vec_c[1]);

  CHECK(&vec_c.begin()[1] == &vec_c[1]);
}

TEST_CASE("iterator random access write", "[iterator]")
{
  string_vector vec{"1", "2", "3"};

  iterator const it{vec.begin()};

  it->push_back('1');

  CHECK(*it == "11");
}

TEST_CASE("iterator random access comparison", "[iterator]")
{
  const_iterator it1{vec_c.begin()};

  const_iterator it2{vec_c.begin() + 1};

  CHECK(it1 - it2 == -1);

  CHECK(it2 - it1 == 1);

  CHECK(it1 < it2);

  CHECK(it1 <= it2);

  CHECK(it2 > it1);

  CHECK(it2 >= it1);

  CHECK(it1 != it2);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
