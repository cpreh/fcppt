//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_RECORD_HPP_INCLUDED
#define FCPPT_CATCH_RECORD_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/label_name.hpp>
#include <fcppt/record/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace Catch
{
/**
\brief Output specialization for #fcppt::record::object.

\ingroup fcpptcatch
*/
template <typename... Elements>
struct StringMaker<fcppt::record::object<Elements...>>
{
  static std::string convert(fcppt::record::object<Elements...> const &_record)
  {
    return '{' +
           fcppt::algorithm::fold(
               fcppt::record::element_vector<fcppt::record::object<Elements...>>{},
               std::string{},
               [&_record]<typename L, typename T>(fcppt::tag<fcppt::record::element<L,T>>, std::string &&_output) {
                 return std::move(_output) + fcppt::record::label_name<L>() + " = " +
                        fcppt::catch_::convert(fcppt::record::get<L>(_record)) + ", ";
               }) +
           '}';
  }
};

}

#endif
