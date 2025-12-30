//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::duplicate_names::duplicate_names(set &&_set)
    : fcppt::options::
          exception{fcppt::string{FCPPT_TEXT("The following names appear multiple times: ")} + fcppt::output_to_fcppt_string(fcppt::container::output(_set)) + FCPPT_TEXT(".")},
      set_{std::move(_set)}
{
}

fcppt::options::duplicate_names::duplicate_names(duplicate_names const &) = default;

fcppt::options::duplicate_names::duplicate_names(duplicate_names &&) noexcept = default;

fcppt::options::duplicate_names &
fcppt::options::duplicate_names::operator=(duplicate_names const &) = default;

fcppt::options::duplicate_names &
fcppt::options::duplicate_names::operator=(duplicate_names &&) noexcept = default;

fcppt::options::duplicate_names::~duplicate_names() noexcept = default;

fcppt::options::duplicate_names::set const &fcppt::options::duplicate_names::get() const
{
  return this->set_;
}
