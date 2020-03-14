//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <string>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wmissing-prototypes)

namespace
{

namespace motivation
{
//![motivation_string]
void f(std::string const &first_name);

void g()
{
	std::string email_address = "a@b.com";
	f(email_address);
}
//![motivation_string]
void f(std::string const &)
{
}
}

namespace motivation2
{
//![motivation_string_2]
FCPPT_MAKE_STRONG_TYPEDEF(
	std::string,
	first_name
);

FCPPT_MAKE_STRONG_TYPEDEF(
	std::string,
	email_address
);

void f(first_name const &);

void g()
{
	email_address address(std::string{"a@b.com"});

	//f(address); error
}
//![motivation_string_2]
}

namespace strong_typedef_example
{
//! [function]
void f(int vertex_count,bool enable_culling,char character);
//! [function]

void f(int,bool,char)
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4305)
FCPPT_PP_DISABLE_VC_WARNING(4800)

void g()
{
//! [bad_call]
// NOLINTNEXTLINE(readability-implicit-bool-conversion,modernize-use-bool-literals)
f(true,1,'c');
//! [bad_call]
}

FCPPT_PP_POP_WARNING

namespace with_strong_typedef
{

//! [parameters_strong_typedefs]
FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	vertex_count
);

FCPPT_MAKE_STRONG_TYPEDEF(
	bool,
	enable_culling
);

FCPPT_MAKE_STRONG_TYPEDEF(
	char,
	draw_char
);

void f(vertex_count,enable_culling,draw_char);
//! [parameters_strong_typedefs]

void f(vertex_count,enable_culling,draw_char)
{
}
}

namespace with_strong_typedef
{
void named_parameters_call_test()
{
//! [parameter_call]
f(
	vertex_count(1),
	enable_culling(true),
	draw_char('c')
);
//! [parameter_call]
}
}

//! [strong_typedef_is_same]
FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	first
);

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	second
);

static_assert(
	!std::is_same<first,second>::value,
	"Both types must be different"
);
//! [strong_typedef_is_same]

}

namespace motivation2
{
//![get]
void
f(first_name const &_name)
{
	std::cout << _name.get() << '\n';
}
//![get]
}

namespace distance_example
{
//![operators]
FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	distance
);

void f(distance const _d1, distance const _d2)
{
	std::cout << (_d1 - _d2) << '\n';
}
//![operators]

}
}

FCPPT_PP_POP_WARNING

int
main()
{
	strong_typedef_example::g();

	strong_typedef_example::f(1,true,'c');

	strong_typedef_example::with_strong_typedef::named_parameters_call_test();

	motivation::g();

	motivation2::g();

	motivation2::f(motivation2::first_name(std::string{}));

	distance_example::f(distance_example::distance(1),distance_example::distance(2));
}
