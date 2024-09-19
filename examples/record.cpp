//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/record/label_name.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/make_label_arg.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/record/set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wmissing-prototypes)

namespace
{
//! [record_struct_person]
struct person
{
  int age;
  std::string name;
};
//! [record_struct_person]

//! [record_struct_person_print]
void print(std::ostream &_stream, person const &_person)
{
  _stream << "age: " << _person.age << ", "
          << "name: " << _person.name;
}
//! [record_struct_person_print]

namespace record
{
//! [record_make_label]
// age = fcppt::record::label<T> for a unique tag type T
FCPPT_RECORD_MAKE_LABEL(age);

// name = fcppt::record::label<T> for a unique tag type T
FCPPT_RECORD_MAKE_LABEL(name);
//! [record_make_label]

//! [record_elements]
using age_element = fcppt::record::element<age, int>;

using name_element = fcppt::record::element<name, std::string>;
//! [record_elements]

//! [record_object]
using person = fcppt::record::object<age_element, name_element>;
//! [record_object]

void get_set()
{
  //! [record_get_set]
  person test_person{age{} = 1, name{} = std::string("test")};

  std::cout << fcppt::record::get<age>(test_person) << '\n';

  fcppt::record::set<age>(test_person, 2);

  std::cout << fcppt::record::get<age>(test_person) << '\n';
  //! [record_get_set]
}

//! [record_output_label]
template <typename Label, typename... Elements>
void print_label(std::ostream &_stream, fcppt::record::object<Elements...> const &_record)
{
  _stream
      // extract the label name
      << fcppt::record::label_name<Label>()
      << ": "
      // extract the value for the label
      << fcppt::record::get<Label>(_record) << ", ";
}
//! [record_output_label]

//! [record_output]
template <typename... Elements>
void print(std::ostream &_stream, fcppt::record::object<Elements...> const &_record)
{
  // Loop over all types in the record
  fcppt::algorithm::loop(
      fcppt::record::element_vector<fcppt::record::object<Elements...>>{},
      [&_stream, &_record]<typename L, typename T>(fcppt::tag<fcppt::record::element<L, T>>)
      { print_label<L>(_stream, _record); });
}
//! [record_output]

void init_stream()
{
  // ![record_init_stream]
  std::istringstream stream{"42 test"};
  // ![record_init_stream]

  // ![record_init_generic]
  person const result{fcppt::record::init<person>(
      [&stream]<typename L, typename T>(fcppt::record::element<L, T>)
      {
        T input;

        if (!(stream >> input))
        {
          throw std::runtime_error{"failure"};
        }

        return input;
      })};
  // ![record_init_generic]

  print(std::cout, result);
}

}

namespace sprite_ns
{
// ![make_label_arg]
// Parametrize the texture label with an unsigned int.
// template<unsigned I> using texture = fcppt::record::label<T,I> for a unique tag type T
FCPPT_RECORD_MAKE_LABEL_ARG(texture, unsigned);
// ![make_label_arg]

// ![sprite_element]
template <unsigned I>
using sprite_element = fcppt::record::element<texture<I>, std::string>;
// ![sprite_element]

// ![sprite_generic]
template <typename T>
struct sprite_from_ints;

template <unsigned... Ints>
struct sprite_from_ints<std::integer_sequence<unsigned, Ints...>>
{
  using type = fcppt::record::object<sprite_element<Ints>...>;
};

template <unsigned N>
using sprite = typename sprite_from_ints<std::make_integer_sequence<unsigned, N>>::type;
// ![sprite_generic]

void test()
{
  // ![sprite_example]
  using sprite_type = sprite<2U>;

  sprite_type const test_sprite{
      texture<0>{} = std::string("ground"), texture<1>{} = std::string("clouds")};
  // ![sprite_example]
  std::cout << test_sprite << '\n';
}

}

}

FCPPT_PP_POP_WARNING

int main()
try
{
  person const test{.age = 42, .name = "test"};

  print(std::cout, test);

  record::get_set();

  std::cout << '\n';

  std::cout << '\n';

  record::init_stream();

  std::cout << '\n';

  sprite_ns::test();
}
catch(std::exception const &_error)
{
  std::cerr << _error.what() << '\n';
  return EXIT_FAILURE;
}
