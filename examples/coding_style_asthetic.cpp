//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace
{
using result_type = int;

using T1 = int;

using T2 = int;

int expression1(int, int) { return 0; }

int expression2(int) { return 0; }

// ![function_example]
result_type my_function(T1 _arg1, T2 _arg2) { return expression1(expression2(_arg1), _arg2); }
// ![function_example]

// ![struct_example]
struct test
{
  explicit test(int const _arg) : value_(_arg) {}

private:
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_CLANG_WARNING(-Wunused-private-field)
  int value_; // NOLINT(clang-diagnostic-unused-private-field)
  FCPPT_PP_POP_WARNING
};

test make_test(int const _arg) { return test(_arg); }
// ![struct_example]

}

int main()
{
  my_function(1, 2);

  make_test(1);
}
