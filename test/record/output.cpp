//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_std_string.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/label_name.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/record/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_RECORD_MAKE_LABEL(int1_label);
FCPPT_RECORD_MAKE_LABEL(int2_label);

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("record output", "[record]")
{
  using int1_element = fcppt::record::element<int1_label,int>;
  using int2_element = fcppt::record::element<int2_label,int>;

  using record = fcppt::record::object<int1_element, int2_element>;

  CHECK(
    fcppt::output_to_std_string(record{int1_label{} = 5, int2_label{} = 10})
	==
	"{" + fcppt::record::label_name<int1_label>() + " = 5, "
	+ fcppt::record::label_name<int2_label>() + " = 10}");
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
