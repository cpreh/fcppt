//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/noncopyable.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/record/set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("record::object", "[record]")
{
  class copy
  {
  public:
    explicit copy(int const _value) : value_(_value) {}

    [[nodiscard]] int value() const { return value_; }

  private:
    int value_;
  };

  class move_only
  {
    FCPPT_NONCOPYABLE(move_only);

  public:
    explicit move_only(int const _value) : value_{_value}, valid_{true} {}

    move_only(move_only &&_other) noexcept : value_{_other.value_}, valid_{_other.valid_}
    {
      _other.valid_ = false;
    }

    move_only &operator=(move_only &&_other) noexcept
    {
      if (&_other == this)
      {
        return *this;
      }

      value_ = _other.value_;

      valid_ = _other.valid_;

      _other.valid_ = false;

      return *this;
    }

    FCPPT_PP_PUSH_WARNING
    FCPPT_PP_DISABLE_CLANG_WARNING(-Wunneeded-member-function)
    ~move_only() = default;
    FCPPT_PP_POP_WARNING

    [[nodiscard]] int value() const
    {
      CHECK(valid_);

      return value_;
    }

  private:
    int value_;

    bool valid_; // NOLINT(cppcoreguidelines-use-default-member-init)
  };

  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(bool_label);

  FCPPT_RECORD_MAKE_LABEL(copy_label);

  FCPPT_RECORD_MAKE_LABEL(move_only_label);

  using my_record = fcppt::record::object<
      fcppt::record::element<int_label, int>,
      fcppt::record::element<bool_label, bool>,
      fcppt::record::element<copy_label, copy>,
      fcppt::record::element<move_only_label, move_only>>;

  int const arg1{4};

  my_record test{
      int_label{} = arg1,
      bool_label{} = true,
      copy_label{} = copy(42),
      move_only_label{} = move_only{10}};

  CHECK(fcppt::record::get<int_label>(test) == 4);

  CHECK(fcppt::record::get<bool_label>(test));

  CHECK(fcppt::record::get<copy_label>(test).value() == 42);

  CHECK(fcppt::record::get<move_only_label>(test).value() == 10);

  my_record test2(std::move(test));

  CHECK(fcppt::record::get<int_label>(test2) == 4);

  CHECK(fcppt::record::get<bool_label>(test2));

  CHECK(fcppt::record::get<move_only_label>(test2).value() == 10);

  fcppt::record::set<bool_label>(test2, false);

  CHECK_FALSE(fcppt::record::get<bool_label>(test2));

  fcppt::record::set<move_only_label>(test2, move_only{100});

  CHECK(fcppt::record::get<move_only_label>(test2).value() == 100);

  fcppt::record::get<int_label>(test2) = 42;

  CHECK(fcppt::record::get<int_label>(test2) == 42);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
